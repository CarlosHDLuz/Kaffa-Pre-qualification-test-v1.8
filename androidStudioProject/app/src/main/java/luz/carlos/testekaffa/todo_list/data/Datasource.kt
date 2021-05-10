package luz.carlos.testekaffa.todo_list

import android.content.Context
import luz.carlos.testekaffa.R

class Datasource(val context: Context) {
    private val initialFlowerList = flowerList(resources)
    private val flowersLiveData = MutableLiveData(initialFlowerList)

    fun getTodoList(): Array<String> {
        return context.resources.getStringArray(R.array.todo_item_array)
    }

    fun addTodoListItem(description: String) {
        val currentList = flowersLiveData.value
        if (currentList == null) {
            flowersLiveData.postValue(listOf(flower))
        } else {
            val updatedList = currentList.toMutableList()
            updatedList.add(0, flower)
            flowersLiveData.postValue(updatedList)
        }
    }
}