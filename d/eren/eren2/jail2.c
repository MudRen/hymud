 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�ڷ�");
        set("long", @LONG
����ʯ����һ�鰼���ĵط���Լ�������ɼ���������һյ�͵ƣ�����
����ľ���һ�Ŵ������Ϻ��Ҷ��ż�������������ȥ����ڿ����ı�����
��ʪ����������̦��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"jail1",
                "west" : __DIR__"jailroad2",
        ]));
        set("objects", ([
                __DIR__"npc/star_snake" : 1,
        ]) );
        set("item_desc", ([
        "��̦" : "��ɫ����̦�����˶��ڡ�\n",
        "moss" : "��ɫ����̦�����˶��ڡ�\n",
        "ľ��" : "����ľ�������������һ����ʱ�����ӡ�\n",
        "box" : "����ľ�������������һ����ʱ�����ӡ�\n",
        "��" : "һ�Ŷ���һ���ȵ�ľ������������ֵ��Ϣʱ�õġ�\n",
        "bed" : "һ�Ŷ���һ���ȵ�ľ������������ֵ��Ϣʱ�õġ�\n",
    ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
int valid_leave(object me,string dir)
{
        object alert_room,trap_room;
        object guard;   
        if(userp(me) && dir == "north") {
                if (!guard=present("bishe",this_object())) 
                        return 1;
           trap_room = find_object(__DIR__"underjail1");
                if(!objectp(trap_room))
                        trap_room = load_object(__DIR__"underjail1");
                message_vision(HIR"$N����ͻȻ������һ���󶴡�\n"NOR, me);
                message_vision(YEL"$Nһ����������������ȥ��\n"NOR,me);
                message("vision",guard->query("name")+"˵����ѽ��׳ʿС�ġ�\n",this_object());
                me->move(trap_room);
                me-> unconcious();
                return notify_fail("\n");       
        }
        return 1;
} 
