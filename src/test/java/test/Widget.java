package test;

public class Widget {

	private boolean enabled;

	/**
	 * Create new enabled widget
	 */
	public Widget() {
		enabled = true;
	}

	/**
	 * Is the widget currently enabled?
	 * 
	 * @return true if enabled, false otherwise
	 */
	public boolean isEnabled() {
		return enabled;
	}

	/**
	 * Set the widget enable state
	 * 
	 * @param enabled
	 * @return this widget
	 */
	public Widget setEnabled(boolean enabled) {
		this.enabled = enabled;
		return this;
	}
}
