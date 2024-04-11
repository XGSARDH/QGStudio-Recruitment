import com.sardh.www.dao.Impl.UserDaoImpl;
import com.sardh.www.dao.UserDao;
import com.sardh.www.po.User;
import org.junit.Test;

public class TestUserDaoImpl {
    @Test
    public void Testsave(){
        UserDao userDao = new UserDaoImpl();
        User user = new User("3","3","3");
        if(userDao.findByUsername(user.getUsername()) == null){
            System.out.println(userDao.save(user));
        }
        else{
            System.out.println("exist");
        }
    }

    @Test
    public void Test_findByUsername(){
        UserDao userDao = new UserDaoImpl();
        String username = "3";
        User user = userDao.findByUsername(username);
        System.out.println(user == null);

    }

    @Test
    public void Test_update(){
        UserDao userDao = new UserDaoImpl();
        User user = new User("3","3");
        if(userDao.findByUsername(user.getUsername()) != null){
            userDao.update(user);
        }
        else{
            System.out.println("not exist");
        }
    }

    @Test
    public void Test_delete() {
        UserDao userDao = new UserDaoImpl();
        String string = "3";
        userDao.delete(string);
    }
}
