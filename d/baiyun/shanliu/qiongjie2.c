 // Room: qiongjie2.c --- by MapMaker
inherit ROOM; 
void create()
{
        set("short", "���"); 
        set("long", @LONG
�����������̸����ֶ�����Ҫüͷ���壬��Ϊ�����ֱ����ؤ�����ã�����
�Ĵ����ǳ���������󣬵���ֵ���ȴ������Щ�������ӳ��������Ȼ����Ǵ�
��������,����ɥ�����ߣ���Ϊ��Զ�������ڽ�����С��������"����Ӷķ�"��
LONG); 
        //{{ --- by MapMaker
        set("exits",([
        "southeast":__DIR__"qiongjie1",
        "southwest":__DIR__"qiongjie3",
        ]) );
        //}}
        set("outdoors", "shanliu");
        set("objects", ([
        __DIR__"npc/gongsun" :1,
 
        ]) );
        set("coor/x",-50);
        set("coor/y",-650);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
