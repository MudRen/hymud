#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��Ұ");
        set("long", @LONG
���������ǻ�Ұ�ˣ�������ׯ԰������ߡ�̫ƽ���ʮ�����˼ң�һ������
��ɽ����ү�ģ���һ������������ġ�û����֪������������ʲô��Ҳû��֪��
����������ֻ֪��������ǰ����������ׯ԰�����ׯ���������ɸ�ǽ��ǽ�ϵ�����
���С���ǽ�������ţ����Ϲ���һ���Ѿ�����һ���ͭ����
LONG
        );
        set("exits", ([ 
                "northwest": __DIR__"mroad8",
                "west": __DIR__"swamp1",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                "door": "һ�����ţ����Ϲ���һ���Ѿ�����һ���ͭ����\n",
                "����": "һ�����ţ����Ϲ���һ���Ѿ�����һ���ͭ����\n",
                "ͭ��": "���������֣�û�����ף�ֻ��һ��СС��ת�̡�\n",  
                "lock": "���������֣�û�����ף�ֻ��һ��СС��ת�̡�\n",  
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_turn","turn");
}  
int do_turn(string arg){
        object me,room;
        me=this_player();
        
        if (arg=="ת��" || arg == "lock" || arg == "ͭ��") {
                if (!me->query("parrot/����ͷ����") && me->query("parrot/����ү")!=1) {
                        message_vision("$N����ͭ����ת��ת��һ�㶯��û�У�����û�ҵ����š�\n",me);
                        return 1;
                }
           tell_object(me,"������ͭ������ת������ת��������ת��\n");
                tell_object(me,"����û�п�����Ľ����ƺ���ʼҡ��������\n");
                message_vision(HIR"���ؾ���Ȼ���˿�����¶���˸��ض���$Nһ�������Խ��˶��\n"NOR,me);
                room = find_object(__DIR__"pond");
                if(!objectp(room))
                        room = load_object(__DIR__"pond");
                me->move(room);
                return 1;
        }
        return 0;
}   
