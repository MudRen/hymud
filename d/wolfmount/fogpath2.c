 inherit ROOM;
void create()
{
        object con,item;
        set("short", "����ʯ��"); 
        set("long", @LONG
ɽ���������ƣ�С·���Ѷ��ϣ�һ�ԴԲ�֪����С����ɽ����ҡҷ����ֵ����
ʱ�ڣ�бб��ʯ�����仨�ͷס�̤���仨����ɳɳ��֮���ڼž���ɽ�����ƺ�����
����������Ҳ�����˸���ľҶ�Ͱٻ��ķҷ���������Զɽ��䡣
LONG); 
        set("type","road");
        set("exits",([
        "southup":__DIR__"fogpath3",
                "northwest":__DIR__"pubyard",
        ]) );
       set("outdoors", "wolfmount");
        set("objects", ([
                __DIR__"obj/noflower" : 1,
                __DIR__"obj/dropflower" : 1,
       ]) );
        set("coor/x",-650);
        set("coor/y",-750);
        set("coor/z",60); 
        setup();
        con = present("noflower",this_object());

//        replace_program(ROOM);
}  
