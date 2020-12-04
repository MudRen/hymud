inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "С��");
        set("long", @LONG
һ������������С·�������м��úܸߴ��ɼ��������ɫ�������ϣ��ܿ���͹
������˰�һ���Ͱ���ȥ�����۾�һ�������ڣ�֦Ҷïʢ�����������˸�����Ժ��
�С���ֻ����֨���������֦�ϴ��ţ�һ�ξͲ����ˡ�С·��ͷ�����֡� 
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"groad3b",
        "east" : __DIR__"groad4",
        ]));
        set("objects", ([
                __DIR__"npc/boy1": 1,
        ]) );
        set("item_desc", ([
                "ɼ��": "�ܸߴ��ɼ����֦Ҷïʢ�����������˸�����Ժ���С�\n",
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_climb", "climb");
        if( this_player() ) {
                tell_room(__DIR__"tree", this_player()->name() + "���������˹�����\n");
        }
} 
int do_climb(string arg)
{
        if( arg!="tree" && arg!="ɼ��") {
                tell_object(this_player(),"��Ҫ��ʲô��\n");
                return 1;
        } 
        if (this_player()->query_skill("move",1)<50
                || this_player()->query_skill("dodge",1)<50)
                return notify_fail("�������ԣ�û��������ȥ��\n");
        
        message_vision("$N�ֽŲ��ã����ݵ�������·�Ե�ɼ����\n",
                this_player()); 
        tell_room(__DIR__"tree", this_player()->name() + "����������������\n");
        this_player()->move(__DIR__"tree");
        return 1;
} 
int valid_leave(object me, string dir)
{
        tell_room(__DIR__"tree",
                "���µ�" + me->name() + "��" + to_chinese(dir) + "�뿪�ˡ�\n");
        return 1;
}    
