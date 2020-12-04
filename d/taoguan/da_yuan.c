#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "���幬��Ժ");
        set("long", @LONG
��ʯ���̳ɵĵ����ϣ�����ɨ�øɸɾ������������᷿��
��ʿ����ӵĵط��������ǳ�����������Ʈ�������㡣����
��һ������ɫ�Ĵ�����д�ţ�������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"da_dian",
                "east" : __DIR__"kitchen",
                "west" : __DIR__"xiang_fang",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2100);
        set("coor/z",80);
        setup();
} 
void init()
{
        if(query("exits/south")) {
        set("item_desc", ([
                "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
        ]) );
        add_action("do_pull", "pull");
        }
        else {
        set("item_desc", ([
                "door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                "��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
        ]) );
        add_action("do_pull", "pull");
        }
} 
int do_pull(string arg)
{
        object room, me; 
        if( arg=="door" || arg == "��") {
                me = this_player();
                if(query("exits/south")) {
                        write("���ǿ��ŵģ�\n");
                }
                else {
                set("exits/south", __DIR__"taoguan");
                set("item_desc", ([
                 "door": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                 "��": "ͭ���Ĵ��ţ����ǿ��ŵġ�\n",
                 ]) );
                message_vision("$N�򿪴��š�\n", me);
                if( room = find_object(__DIR__"taoguan") ) {
                        message("vision", "���Ŵ�������˿�����\n", room);
                        room->set("exits/north", __FILE__);
                        call_out("closedoor", 5, room);
                }
                }
        }
        else {
                 write("��Ҫ��ʲô��\n");
        }
        return 1;
} 
int closedoor(object room)
{
        message("vision", "�����ֱ������ˡ�\n", room);
        message("vision", "�����ֱ������ˡ�\n", this_object());
        set("item_desc", ([
                "door": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
                "��": "ͭ���Ĵ��ţ����ǹ��ŵģ��������(pull)�š�\n",
        ]) );
        room->delete("exits/north");
        delete("exits/south");
}    
