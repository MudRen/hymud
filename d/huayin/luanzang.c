// luanzang.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG                                   
����һƬ�������ߵ�����ڣ���Ө�ӳ£�һ�����紵������
�Ϲ��𼸸�СС�����У����ų����ֽǮ����������...��������
һ�󷢽������Ǿ����뿪����ɡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               //"north":__DIR__"luanzang", ���ﵽ�����£�0:00-3:00����ͨ����
               "southup":__DIR__"tupo",
              // "east" : __DIR__"xiaolu7",
               
        ]) );

        //set("objects",([__DIR__"npc/door_guard" : 2,]) );
        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
