import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;

public class Tmp {
	public static void main (String [] args) {
		Display display = new Display ();
		Shell shell = new Shell (display);
		GridLayout gridLayout = new GridLayout ();
		shell.setLayout (gridLayout);

		Button button0 = new Button(shell, SWT.PUSH);
		button0.setText ("button0");
		
		Text text = new Text(shell, SWT.BORDER | SWT.FILL);
		text.setText ("Text Field");
		
		shell.setSize(500, 400);
		//shell.pack();
		shell.open();

		while (!shell.isDisposed ()) {
			if (!display.readAndDispatch ())
				display.sleep ();
		}
		display.dispose ();
	}
}