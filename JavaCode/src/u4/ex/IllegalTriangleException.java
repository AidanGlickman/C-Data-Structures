package u4.ex;

public class IllegalTriangleException extends RuntimeException{
    public IllegalTriangleException() {
        super();
    }

    public IllegalTriangleException(String message){
        super(message);
    }
}
