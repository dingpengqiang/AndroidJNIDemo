package com.noway.android.jnidemo;


public class Student {

    /**
     * 学生id
     */
    public Long id;

    /**
     * 姓名
     */
    private String name;

    /**
     * 年龄
     */
    private int  age;

    /**
     * 性别  true 男生  false 女生
     */
    private boolean gender;

    /**
     * 年级
     */
    private String clazz;


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public boolean isGender() {
        return gender;
    }

    public void setGender(boolean gender) {
        this.gender = gender;
    }

    public String getClazz() {
        return clazz;
    }

    public void setClazz(String clazz) {
        this.clazz = clazz;
    }


}
