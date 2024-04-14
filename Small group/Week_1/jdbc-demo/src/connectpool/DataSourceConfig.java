package connectpool;

import java.lang.reflect.Field;
import java.util.Properties;
import java.util.Set;

public class DataSourceConfig {

    private String driver;
    private String url;
    private String username;
    private String password;
    private String initSize;
    private String maxSize;
    private String health;
    private String delay;
    private String period;
    private String timeout;
    private String waittime;

    public DataSourceConfig(){
        try {
            Properties properties = new Properties();
            properties.load(DataSourceConfig.class.getClassLoader().getResourceAsStream("db.properties"));
            Set<Object> keySet = properties.keySet();
            for (Object key : keySet) {
                String filedName = key.toString().split("\\.")[1];
                String filedValue = properties.getProperty(key.toString());
                Field field = this.getClass().getDeclaredField(filedName);
                field.setAccessible(true);
                field.set(this, filedValue);
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public void soutString(){
        System.out.println(driver);
        System.out.println(url);
        System.out.println(username);
        System.out.println(password);
        System.out.println(initSize);
        System.out.println(maxSize);
        System.out.println(health);
        System.out.println(delay);
        System.out.println(period);
        System.out.println(timeout);
        System.out.println(waittime);
    }

    public String getDriver() {
        return driver;
    }

    public void setDriver(String driver) {
        this.driver = driver;
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getInitSize() {
        return initSize;
    }

    public void setInitSize(String initSize) {
        this.initSize = initSize;
    }

    public String getMaxSize() {
        return maxSize;
    }

    public void setMaxSize(String maxSize) {
        this.maxSize = maxSize;
    }

    public String getHealth() {
        return health;
    }

    public void setHealth(String health) {
        this.health = health;
    }

    public String getDelay() {
        return delay;
    }

    public void setDelay(String delay) {
        this.delay = delay;
    }

    public String getPeriod() {
        return period;
    }

    public void setPeriod(String period) {
        this.period = period;
    }

    public String getTimeout() {
        return timeout;
    }

    public void setTimeout(String timeout) {
        this.timeout = timeout;
    }

    public String getWaittime() {
        return waittime;
    }

    public void setWaittime(String waittime) {
        this.waittime = waittime;
    }

    @Override
    public String toString() {
        return "DataSourceConfig{" +
                "driver='" + driver + '\'' +
                ", url='" + url + '\'' +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", initSize='" + initSize + '\'' +
                ", maxSize='" + maxSize + '\'' +
                ", health='" + health + '\'' +
                ", delay='" + delay + '\'' +
                ", period='" + period + '\'' +
                ", timeout='" + timeout + '\'' +
                ", waittime='" + waittime + '\'' +
                '}';
    }
}

