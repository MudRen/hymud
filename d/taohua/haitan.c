#include <ansi.h>

inherit ROOM;

void rtaohua( object ob,object obj ) ;

void create()
{
    set("short", "��̲");
    set("long", @LONG
�����һ���ǰ�ĺ�̲��������һ���޼ʵĴ󺣣���������һƬ�һ��֡�
�����ĺ��������죬���ɫ��ɳ̲���ۺ���һ�����һ�ж�����ô��������
����һ�Ҵ�(chuan)��
LONG );
    set("item_desc", ([
        "chuan" : "�����һ���������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
        "south" :__DIR__"tao_in",
    ]));
	set("objects", ([
		"quest/skills2/wunon/yu/yutan" : 3,
  	])); 

//    set("no_clean_up", 0);
    set("outdoors", "taohua");
    setup();
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob,obj ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��������������С�\n", ob);
obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
if (obj) obj->move("/d/taohua/dahai");
    ob ->move("/d/taohua/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("rtaohua", 10 , ob,obj );
    return 1 ;
}
void rtaohua( object ob,object obj )
{
  tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
  ob->move ("/d/jiaxing/jiaxinggang") ;
if (obj) obj->move("/d/jiaxing/jiaxinggang");  
}