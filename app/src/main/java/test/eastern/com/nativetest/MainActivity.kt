package test.eastern.com.nativetest

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        breakpadInit(cacheDir.absolutePath)
        btn_test.setOnClickListener {
            testNativeCrash()
        }
    }

    external fun breakpadInit(dump_dir: String)
    external fun testNativeCrash()

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("crash-sdk")
        }
    }
}
