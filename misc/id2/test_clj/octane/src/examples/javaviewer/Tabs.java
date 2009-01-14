import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Text;

public class Tabs {

	public static void main(String[] args) {
		Display display = new Display();
		final Shell shell = new Shell(display);
		shell.setText("Tab Folder Example");
		shell.setSize(450, 250);

		final TabFolder tabFolder = new TabFolder(shell, SWT.BORDER);

		for (int loopIndex = 0; loopIndex < 4; loopIndex++) {
			TabItem tabItem = new TabItem(tabFolder, SWT.NULL);
			tabItem.setText("Tab " + loopIndex);

			Text text = new Text(tabFolder, SWT.BORDER);
			text.setText("This is page " + loopIndex);
			tabItem.setControl(text);
		}
		tabFolder.setSize(400, 200);

		shell.open();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch())
				display.sleep();
		}
		display.dispose();
	}
}
