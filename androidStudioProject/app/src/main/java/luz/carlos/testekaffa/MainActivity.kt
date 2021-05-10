package luz.carlos.testekaffa

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import luz.carlos.testekaffa.todo_list.SimpleTodoListActivity

class MainActivity : AppCompatActivity() {

    private lateinit var simpleTodoList: Button
    private lateinit var worldClockButton: Button
    private lateinit var uxPrototypeButton: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        simpleTodoList = findViewById(R.id.simple_todo_list)
        worldClockButton = findViewById(R.id.world_clock_button)
        uxPrototypeButton = findViewById(R.id.ux_prototype_button)

        var intent: Intent
        simpleTodoList.setOnClickListener {
            intent = Intent(this, SimpleTodoListActivity::class.java)
            startActivity(intent)
        }
        worldClockButton.setOnClickListener {
            intent = Intent(this, WorldClockActivity::class.java)
            startActivity(intent)
        }
        uxPrototypeButton.setOnClickListener {
            intent = Intent(this, UxPrototypeActivity::class.java)
            startActivity(intent)
        }

    }
}