public class User {
    private String userName;
    private String otherInformation;

    public User(String userName, String otherInformation) {
        this.userName = userName;
        this.otherInformation = otherInformation;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getOtherInformation() {
        return otherInformation;
    }

    public void setOtherInformation(String otherInformation) {
        this.otherInformation = otherInformation;
    }
}
