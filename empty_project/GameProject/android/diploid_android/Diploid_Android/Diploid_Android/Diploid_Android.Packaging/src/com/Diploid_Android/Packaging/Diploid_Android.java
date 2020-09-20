package com.Diploid_Android.Packaging;

import android.app.NativeActivity;
import android.os.Bundle;
import android.widget.EditText;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.view.View;
import java.lang.Runnable;
import android.view.Display;
import android.view.WindowManager;
import android.graphics.Point;

public class Diploid_Android extends NativeActivity
{
	NativeActivity AppActivity;
	WindowManager WM;
	Display disp;

	int window_x;
	int window_y;

	//画面のX軸方向の大きさ
	public void RealScreenSize()
	{
		AppActivity = this;

		Display display = AppActivity.getWindowManager().getDefaultDisplay();
        Point point = new Point();

        display.getRealSize(point);

		window_x = point.x;
		window_y = point.y;
	}
}