package luz.carlos.testekaffa

import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import com.android.volley.Request
import com.android.volley.RequestQueue
import com.android.volley.toolbox.JsonObjectRequest
import com.android.volley.toolbox.Volley
import org.json.JSONObject
import java.text.DateFormat
import java.text.SimpleDateFormat
import java.time.LocalDateTime
import java.time.ZoneId
import java.time.format.DateTimeFormatter
import java.util.*

const val serverURL = "http://worldclockapi.com/api/json/utc/now"
const val CURRENT_DATE_TIME = "currentDateTime"
const val TIME_ZONE_NAME = "timeZoneName"
const val UTC_OFFSET = "utcOffset"

class WorldClockActivity : AppCompatActivity() {

    private val tag = "WorldClockActivity"

    private lateinit var textView: TextView
    private lateinit var button: Button
    private lateinit var queue: RequestQueue

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_world_clock)

        textView = findViewById(R.id.text_view)
        button = findViewById(R.id.button)

        button.setOnClickListener { onClick() }

        queue = Volley.newRequestQueue(this)

    }

    private fun onClick() {

        // Request a string response from serverURL.
        var jsonObject = JSONObject()
        val stringRequest = JsonObjectRequest(Request.Method.GET, serverURL, jsonObject,
            { response ->
                jsonObject = response
                Log.d(tag, "jsonObject: $jsonObject")

//              2021-05-08T18:50Z",
//              yyyy-MM-dd HH mmX

                val dateStr = jsonObject.getString(CURRENT_DATE_TIME)
                Log.d(tag, "dateStr: $dateStr")
                val df = SimpleDateFormat("yyyy-MM-dd'T'HH:mmX", Locale.ENGLISH)
                df.setTimeZone(TimeZone.getTimeZone("UTC"))
                val date: Date = df.parse(dateStr)
                Log.d(tag, "date: $date")
                df.setTimeZone(TimeZone.getDefault())
                val formattedDate: String = df.format(date)
                Log.d(tag, "formattedDate: $formattedDate")
                textView.text = "UTC\n" + formattedDate + "\n\nLocal TimeZone\n" + date

            },
            { response ->
                Log.e(tag, "requestError: $response")
                textView.text = "ERROR:\n$response"
            }
        )
        // Add the request to the RequestQueue.
        queue.add(stringRequest)
    }
}