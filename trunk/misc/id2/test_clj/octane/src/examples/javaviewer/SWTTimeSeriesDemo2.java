/* ===========================================================
 * JFreeChart : a free chart library for the Java(tm) platform
 * ===========================================================
 *
 * (C) Copyright 2000-2007, by Object Refinery Limited and Contributors.
 *
 * Project Info:  http://www.jfree.org/jfreechart/index.html
 *
 * This library is free software; you can redistribute it and/or modify it 
 * under the terms of the GNU Lesser General Public License as published by 
 * the Free Software Foundation; either version 2.1 of the License, or 
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public 
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, 
 * USA.  
 *
 * [Java is a trademark or registered trademark of Sun Microsystems, Inc. 
 * in the United States and other countries.]
 *
 * ---------------------
 * SWTTimeSeriesDemo.java
 * ---------------------
 * (C) Copyright 2006, 2007, by Object Refinery Limited and Contributors.
 *
 * Original Author:  David Gilbert (for Object Refinery Limited);
 * Contributor(s):   Henry Proudhon (henry.proudhon AT ensmp.fr);
 *
 * Changes
 * -------
 * 30-Jan-2007 : New class derived from TimeSeriesDemo.java (HP);
 * 
 */


import java.awt.Color;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.eclipse.swt.SWT;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYItemRenderer;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.data.time.Second;
import org.jfree.data.time.TimeSeries;
import org.jfree.data.time.TimeSeriesCollection;
import org.jfree.data.xy.XYDataset;
import org.jfree.experimental.chart.swt.ChartComposite;
import org.jfree.ui.RectangleInsets;

/**
 * An example of a time series chart.  For the most part, default settings are 
 * used, except that the renderer is modified to show filled shapes (as well as 
 * lines) at each data point.
 */
public class SWTTimeSeriesDemo2
{

    /**
     * Creates a chart.
     * 
     * @param dataset  a dataset.
     * 
     * @return A chart.
     */
    private static JFreeChart createChart(XYDataset dataset) {

        JFreeChart chart = ChartFactory.createTimeSeriesChart(
            "Legal & General Unit Trust Prices",  // title
            "Date",                               // x-axis label
            "Price Per Unit",                     // y-axis label
            dataset,                              // data
            true,                                 // create legend?
            true,                                 // generate tooltips?
            false                                 // generate URLs?
        );

        chart.setBackgroundPaint(Color.white);
        XYPlot plot = (XYPlot) chart.getPlot();        
        plot.setBackgroundPaint(Color.white);
        plot.setDomainGridlinePaint(Color.lightGray);
        plot.setRangeGridlinePaint(Color.lightGray);
        
        plot.setAxisOffset(new RectangleInsets(5.0, 5.0, 5.0, 5.0));
        plot.setDomainCrosshairVisible(true);
        plot.setRangeCrosshairVisible(true);
        
        XYItemRenderer r = plot.getRenderer();
        if (r instanceof XYLineAndShapeRenderer) {
            XYLineAndShapeRenderer renderer = (XYLineAndShapeRenderer) r;
            renderer.setBaseShapesVisible(true);
            renderer.setBaseShapesFilled(true);
        }
        
        //DateAxis axis = (DateAxis) plot.getDomainAxis();
        //axis.setDateFormatOverride(new SimpleDateFormat("MMM-yyyy"));
        
        return chart;

    }
    
    /**
     * Creates a dataset, consisting of two series of monthly data.
     *
     * @return The dataset.
     */
    private static XYDataset createDataset() {

        TimeSeries s1 = new TimeSeries("L&G European Index Trust", Second.class);
        Date d = new Date();
        
        // "yyyy.MM.dd G 'at' HH:mm:ss z"
        // "EEE, MMM d, ''yy"
        // "Feb 14 06:02:17 2009";
        SimpleDateFormat df = new SimpleDateFormat("MMM d HH:mm:ss yyyy");
        Date d2;
        try {
			d2 = df.parse("Feb 14 06:02:17 2009");
		} catch (ParseException e) {
			e.printStackTrace();
			throw new RuntimeException("Err: " + e.getMessage());
		}
		d = d2;
        
        s1.add(new Second(new Date(d.getTime() + 500)), 181.8);
        s1.add(new Second(new Date(d.getTime() + 1000)), 167.3);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 3000)), 153.8);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 4000)), 167.6);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 5000)), 158.8);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 6000)), 148.3);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 7000)), 153.9);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 8000)), 142.7);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 9000)), 123.2);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 9000)), 131.8);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 10000)), 139.6);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 10100)), 142.9);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 10200)), 138.7);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 10300)), 137.3);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 11000)), 143.9);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 12000)), 139.8);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 14000)), 137.0);
        s1.addOrUpdate(new Second(new Date(d.getTime() + 15000)), 132.8);

        TimeSeries s2 = new TimeSeries("L&G UK Index Trust", Second.class);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 1500)), 129.6);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 3500)), 123.2);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 4500)), 117.2);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 5500)), 124.1);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 6500)), 122.6);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 6500)), 119.2);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 7500)), 116.5);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 8500)), 112.7);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 9500)), 101.5);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 10500)), 106.1);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 11500)), 110.3);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 12500)), 111.7);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 13500)), 111.0);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 14500)), 109.6);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 15500)), 113.2);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 16500)), 111.6);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 17500)), 108.8);
        s2.addOrUpdate(new Second(new Date(d.getTime() + 18500)), 101.6);
        
        TimeSeriesCollection dataset = new TimeSeriesCollection();
        dataset.addSeries(s1);
        dataset.addSeries(s2);
        
        return dataset;
    }
    
    /**
     * Starting point for the demonstration application.
     *
     * @param args  ignored.
     */
    public static void main(String[] args) {
        final JFreeChart chart = createChart(createDataset());
        final Display display = new Display();
        Shell shell = new Shell(display);
        shell.setSize(600, 300);
        shell.setLayout(new FillLayout());
        shell.setText("Time series demo for jfreechart running with SWT");
        
        ChartComposite frame = new ChartComposite(shell, SWT.NONE, chart, true);
        frame.setDisplayToolTips(true);
        frame.setHorizontalAxisTrace(false);
        frame.setVerticalAxisTrace(false);
        
        shell.open();
        while (!shell.isDisposed()) {
            if (!display.readAndDispatch())
                display.sleep();
        }
    }

}
