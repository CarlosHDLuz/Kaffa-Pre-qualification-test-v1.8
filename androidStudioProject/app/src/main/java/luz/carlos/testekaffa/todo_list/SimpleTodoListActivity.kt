package luz.carlos.testekaffa.todo_list

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.RecyclerView
import com.firebase.ui.database.FirebaseRecyclerAdapter
import com.firebase.ui.database.FirebaseRecyclerOptions
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.Query
import com.google.firebase.database.ktx.database
import com.google.firebase.ktx.Firebase
import luz.carlos.testekaffa.R
import luz.carlos.testekaffa.todo_list.data.TodoListItem


const val TODO_LIST_DATABASE_PATH = "todo_list"
const val DESCRIPTION = "description"

class SimpleTodoListActivity : AppCompatActivity() {

    private lateinit var adapter: FirebaseRecyclerAdapter<*, *>
    private lateinit var newItemEditText: EditText

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_simple_todo_list)

        newItemEditText = findViewById(R.id.add_new_item_edittext)

        val recyclerView: RecyclerView = findViewById(R.id.todo_list_recycler_view)

        val query: Query = FirebaseDatabase.getInstance()
            .reference
            .child(TODO_LIST_DATABASE_PATH)

        val options: FirebaseRecyclerOptions<TodoListItem?> = FirebaseRecyclerOptions.Builder<TodoListItem>()
            .setQuery(query
            ) { snapshot -> TodoListItem(snapshot.child(DESCRIPTION).value.toString()) }
            .build()

        class TodoListViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
            private val flowerTextView: TextView = itemView.findViewById(R.id.todolist_item_text)

            fun bind(word: String) {
                flowerTextView.text = word
            }
        }

        adapter =
            object : FirebaseRecyclerAdapter<TodoListItem?, TodoListViewHolder?>(options) {
                override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): TodoListViewHolder {
                    // Create a new instance of the ViewHolder, in this case we are using a custom
                    // layout called R.layout.message for each item
                    val view: View = LayoutInflater.from(parent.context)
                        .inflate(R.layout.todolist_item, parent, false)
                    return TodoListViewHolder(view)
                }

                override fun onBindViewHolder(
                    holder: TodoListViewHolder,
                    position: Int,
                    model: TodoListItem
                ) {
                    holder.bind(model.description?:"")
                }
            }
        recyclerView.adapter = adapter

    }

    override fun onStart() {
        super.onStart()

        adapter.startListening()
    }

    override fun onStop() {
        super.onStop()

        adapter.stopListening()
    }

    fun addNewItemButtononClick(view: View) {
        if (newItemEditText.text.isNotEmpty() && newItemEditText.text.isNotBlank())
        Firebase.database.reference.child(TODO_LIST_DATABASE_PATH).push()
            .setValue(
                TodoListItem(newItemEditText.text.toString())
            )
        else {
            Toast.makeText(
                this@SimpleTodoListActivity,
                resources.getString(R.string.empty_or_blank_alert),
                Toast.LENGTH_SHORT
            ).show()
        }
    }
}