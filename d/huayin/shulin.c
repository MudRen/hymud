// shulin.c

inherit ROOM;
void create()
{
        set("short","С����");
        set("long",@LONG                                   
������һСƬ�����֣���紵��������ɳɳ���졣��˵����
��Ҷ���ǿ�������д�ֵģ�Ҳ��֪���ǲ�����ġ�������һ��Ƭ
ׯ�ڵء�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "east":__DIR__"miaopu4",
               "north":__DIR__"tulu3",
               
        ]) );

	set("NONPC",1);

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
