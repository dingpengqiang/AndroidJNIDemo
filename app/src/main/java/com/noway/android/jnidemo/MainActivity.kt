package com.noway.android.jnidemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*
import java.util.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()

    }



    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String

    /**
     * 传递int 返回int
     */
    private external fun intFromJNI(value:Int):Int

    /**
     *传递Boolean 返回Boolean
     */
    private external fun booleanFromJNI(value: Boolean):Boolean

    /**
     *传递Char 返回Char
     */
    private external fun charFromJNI(value: Char):Char

    /**
     *传递String 返回String
     */
    private external fun stringFromJNI2(value: String): String


    /**
     *传递Any 返回String
     */
    private external fun objectFromJNI(student: Student): String


    private external fun callJavaFromJNI()

    fun onClick(view: View) {
        when(view.id){
            R.id.btn_int -> btn_int.text = intFromJNI(10).toString()

            R.id.btn_char -> btn_char.text = charFromJNI('D').toString()

            R.id.btn_string -> btn_string.text = stringFromJNI2("传递String值")

            R.id.btn_boolean->btn_boolean.text = if (booleanFromJNI(false)) {
                                                    "true"
                                                }else{
                                                    "false"
                                                }
            R.id.btn_object ->{
                var student = Student()
                student.id = 1
                student.name = "学生1"
                student.age = 18
                student.isGender = true;
                student.clazz = "高三"
                btn_object.text = objectFromJNI(student)
            }
            R.id.btn_call_java ->callJavaFromJNI()
            else->{
                Toast.makeText(this, "找不到该View", Toast.LENGTH_SHORT).show()
            }
        }
    }

    fun showCallJava(){
        Toast.makeText(this, "JNI调用C、C++", Toast.LENGTH_SHORT).show()
    }

    fun showCallJava2(msg:String){
        Toast.makeText(this, msg, Toast.LENGTH_SHORT).show()
    }
}
