#include <ansi.h> 
inherit ROOM;
void create() 
{ 
    set("short", "����"); 
    set("long", @long
������ҷǳ�խС������ʮ�ֳ�ʪ����ֵ��ǣ����ҷǳ���������
͸�����ߣ������һ���������������ǽ����һ�����ӣ�վ������
�ϣ�����Դ������ݶ���ʯ��(rock)��
long 
    ); 
    set("exits", ([ 
        ])); 
	set("item_desc", ([
                "����": "ʯͷ��̵����ӣ����������ȥ��\n",
                "box": "ʯ�͵�̵����ӣ����������ȥ��\n" ,
                "ʯ��": "һ�����ڲ�ͬ��ʯ�飬�ƺ������ƶ�(move)��\n",
                "rock" : "һ�����ڲ�ͬ��ʯ�飬�ƺ������ƶ�(move)��\n",
        ]) );
    set("indoors","shanxi"); 
        set("coor/x",-480);
        set("coor/y",-260);
        set("coor/z",50);
        setup(); 
} 
void init()
{
add_action("do_climb","climb");
add_action("do_move","move");
}
int do_climb(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "����" || arg == "box" || arg == "up" )
        {
        	me = this_player();
        	message_vision("$N�����˶�������ӣ��ֽŲ��ã�������������ȥ��\n", me);
        	me->set_temp("marks/climb_box",1);
        	write("���ڿ�������ʯ���ˡ�\n");
       	return 1;
        }
}

int do_move(string arg)
{
        object room;
        object me;
        
        me = this_player();
        
        if(!arg || arg=="")
        {
                write("��Ҫ�ƶ�ʲô��\n");
                return 1;
        }
        if( arg == "ʯ��" || arg == "rock" )
        {
        	if(!me->query_temp("marks/climb_box"))
        		return notify_fail("ʯ���е�ߣ��㴥��������\n");
                message_vision("$N���������İ�ʯ���ƶ�����¶����һ������$N�Ǳ�������������ȥ��\n",me);
                me->delete_temp("marks/climb_box");
        	room = find_object(__DIR__"alou");
        	if(!objectp(room)) room = load_object(__DIR__"alou");
        	message("vision","���ϵ�ʯ��ͻȻ���ƿ���"+me->name()+"�������Ǳ�������������\n",room);
        	me->move(room);
       	return 1;
        }
}