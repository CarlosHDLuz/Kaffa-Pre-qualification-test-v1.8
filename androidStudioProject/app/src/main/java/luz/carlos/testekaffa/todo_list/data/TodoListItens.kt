package luz.carlos.testekaffa.todo_list.data

import android.content.res.Resources

fun todoListItem(resources: Resources): List<TodoListItem> {
    return listOf(
        TodoListItem("Add more tasks to this list"),
        TodoListItem("Hire Carlos Luz"),
        TodoListItem("Get vaccinated")
    )
}