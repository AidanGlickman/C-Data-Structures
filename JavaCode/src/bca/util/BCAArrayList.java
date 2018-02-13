package bca.util;

import java.util.Arrays;

public class BCAArrayList implements BCAList{
    protected Object[] list = new Object[5];
    protected int listSize = 0;

    private void expand(){
        list = Arrays.copyOf(list, list.length+5);
    }

    @Override
    public void add(Object o) {
        if(listSize == list.length)
            expand();
        list[listSize++] = o;
    }

    @Override
    public void add(int index, Object o) {
        if(index > listSize || index < 0)
            throw new IndexOutOfBoundsException("Index of " + index + " is out of bounds");

        if(listSize == list.length)
            expand();

        for(int i = listSize-1; i > index; i--)
            list[i] = list[i-1];
        list[index] = o;

        listSize++;
    }

    @Override
    public void clear() {
        listSize = 0;
        list = new Object[5];
    }

    @Override
    public boolean contains(Object o) {
        for(int i = 0; i < listSize; i++)
            if(list[i].equals(o))
                return true;

        return false;
    }

    @Override
    public Object get(int index) {
        if(index >= listSize || index < 0)
            throw new IndexOutOfBoundsException();

        return list[index];
    }

    @Override
    public int indexOf(Object o) {
        for(int i = 0; i < listSize; i++)
            if(list[i].equals(o))
                return i;

        return -1;
    }

    @Override
    public boolean isEmpty() {
        for(int i = 0; i < listSize; i++)
            if(list[i] != null)
                return false;

        return true;
    }

    @Override
    public int lastIndexOf(Object o) {
        int index = -1;

        for(int i = 0; i < listSize; i++)
            if(list[i].equals(o))
                index = i;

        return index;
    }

    @Override
    public Object remove(int index) {
        if(index >= listSize || index < 0)
            throw new IndexOutOfBoundsException("Index " + index + " is out of bounds.");

        Object obj = list[index];

        for(int i = index; i < listSize; i++){
            list[i] = list[i+1];
        }

        listSize--;
        return obj;
    }

    @Override
    public boolean remove(Object o) {
        for(int i = 0; i < listSize; i++)
            if(list[i].equals(o)) {
                remove(i);
                return true;
            }
        return false;
    }

    @Override
    public int size() {
        return listSize;
    }

    @Override
    public String toString() {
        String str = "";
        for(int i = 0; i < listSize; i++)
            str += i + ": " + list[i] + "; ";
        return str;
    }
}
