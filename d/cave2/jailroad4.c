 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ص���ͷ");
        set("long", @LONG
ʯ����������������������̦��������ɽʯ����ɫ�� 
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad3", 
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init()
{
        add_action("do_push", "push");
} 
int do_push(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"mouseroom1");
        message_vision("��Ƭ��̦�������ܣ���ȴ�д���ѿ�����������̦����¶��һ��������Ķ�Ѩ��������
�ⶼ�Ʋ�����\n",me);
        tell_object(me,"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n");
        me->move(room);
        return 1;
}     
