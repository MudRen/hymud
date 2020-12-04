 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�η�");
        set("long", @LONG
˵���η���ȴû��������û�������ıڿյ����ģ���Ҳû��������
����������һ��ܴ��������ڵ��ϣ���������ٽ��ء���������һ����
������Ŀס�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jail2",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("item_desc", ([
                "����": "һ������ٽ��ص����壬��������Ǹ���ӡ�\n",
                "tieban": "һ������ٽ��ص����壬��������Ǹ���ӡ�\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init()     {
        add_action("do_push","push");
} 
void close_passage()
{
        object room; 
        if (room = find_object("/d/eren2/underjail1")) {
                if (!room->query("exits/up")) return;
                message("vision","�������һ���ֵ���������ס�˳��ڡ�\n",room);
                room->delete("exits/up");
        }
        message("vision", "���塰�䡱��һ���ֵ���ȥ��ס����ӡ�\n", this_object() );
} 
void check_trigger()
{
        object room;
        if( query("trigger")==5)  { 
        if( room = find_object(__DIR__"underjail1") ) {
                message("vision","���ϵĴ������Ȼ֨֨�¸µ������ƶ�������¶��һ��խ�졣\n",room );
                room->set("exits/up", __DIR__"jail1");
                message("vision","������֨֨�¸µ��ƶ�������¶��һ��խ�졣\n",this_object());
        }
                delete("trigger");
                call_out("close_passage", 10);
        }
}   
int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "����" && arg != "tieban")) {
                return 0;
        }
        room = find_object(__DIR__"underjail1");
        if(!objectp(room)) 
                room = load_object(__DIR__"underjail1");   
        if (room->query("exits/up"))
                return notify_fail("�����Ѿ������ˡ�\n");
        message_vision(WHT"$N���һ�����þ�ȫ�������������塣\n"NOR, this_player());
        add("trigger", 1);
        check_trigger();
        return 1;
}  
void reset()
{
        ::reset();
        delete("trigger");
}
 
