 // Room: qiongjie1.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "���"); 
        set("long", @LONG
�����������̸����ֶ�����Ҫüͷ���壬��Ϊ�����ֱ����ؤ�����ã�����
�Ĵ����ǳ���������󣬵���ֵ���ȴ������Щ�������ӳ��������Ȼ����Ǵ�
��������������ɥ�����ߣ���Ϊ��Զ�������ڽ�����С��������"����Ӷķ�"��
LONG);
        //{{ --- by MapMaker
        set("exits",([
        "northwest":__DIR__"qiongjie2",
    "east": "/d/baiyun/southsearoad1",
        ]) );
        //}}
        set("objects", ([
        __DIR__"npc/beggar" :1,
        __DIR__"npc/scavenger"  :1,
        ]) );
        set("outdoors", "shanliu");
        set("coor/x",-30);
        set("coor/y",-660);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
