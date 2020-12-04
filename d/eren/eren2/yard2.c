#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
����İ����Ϊ��ª�������ﵽ�������Żҳ������������û����������һ��
�״���ɢ�ڵ��ϣ������˺���һ����̦����ǽ�аѶ��˵ĳ�ǹ��ǹ�����û��һ
˿�������ǲ�����������һ��һ�εģ���Щ�����Ⱦ�����������֩����æ������
��֯��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"yard1",
        ]));
        set("item_desc", ([
                "��ǹ": "һ������ͨͨ�ĳ�ǹ��ǹ�����û��һ˿����\n",
                "�״�": "һ���ƾɵ��״�(bag)���Ѿ�������װʲô�����ˡ�\n",
                "��̦": "Ҳ����̫��ʪ��Ե�ʣ��״��ϳ���һ����̦(moss)��\n",
                "����": "����(web)��մ�����ҳ�����ֻ֩����æµ�����޲��ţ�������˿(thread)����������\n",
                "��˿": "����ϸ�ؿ��˿����и���˿�ر���֣��ƺ��Ǹ�������ϸ˿(metalthread)��\n",
                "������ϸ˿": "���ϸ˿����������pull��������ϸ˿�ĺ����ƺ����ž��壬��
���ز��ų����϶�������������\n",
                "bag": "һ���ƾɵ��״����Ѿ�������װʲô�����ˡ�\n",
                "moss": "Ҳ����̫��ʪ��Ե�ʣ��״��ϳ���һ����̦��\n",
                "web": "������մ�����ҳ�����ֻ֩����æµ�����޲��ţ�������˿����������\n",
                "thread": "����ϸ�ؿ��˿����и���˿�ر���֣��ƺ��Ǹ�������ϸ˿(metalthread)��\n",
                "metalthread": "���ϸ˿����������pull��������ϸ˿�ĺ����ƺ����ž��壬��
���ز��ų����϶�������������\n",
        ]) );
        set("alarm",0);
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_pull", "pull");
}  
int do_pull(string arg){
        
        object me, guard, op_room, room, another;
            
        me = this_player();
        if(!arg || (arg != "������ϸ˿" && arg != "ϸ˿"
                && arg != "metalthread" )) {
                return 0;
        }
        if (guard=present("guardian",this_object()))
                return notify_fail("�������һ������͵͵���������ʲô����\n");
        seteuid(getuid());
        op_room = find_object(__DIR__"controlroom");
        if(!objectp(op_room)) 
                op_room = load_object(__DIR__"controlroom");       
        if (op_room->query("thread")) {
                message_vision("$Nһ����˿����Ȼ��������������˼���������\n", me);
                another = new(__DIR__"npc/guarda");
                another->move(this_object());
                add("alarm",1);
                if (query("alarm")>=3) {
                        another = new(__DIR__"npc/guarda");
                        another->move(this_object());
                        another = new(__DIR__"npc/guarda");
                        another->move(this_object());
                        message("vision","����˵������������м����ֵ��ǰڲ�ƽ���ˣ���\n",this_object());
                }
                return 1;
        }
        room = find_object(__DIR__"studyroom");
        if(!objectp(room)) 
                room = load_object(__DIR__"studyroom");   
        message_vision(HIW"$Nֻ�����񡱵�һ�������ţ�����һ������������죬�����µ�
һ�ѿݲ�ͻȻ�����ƶ���¶��һ��������\n"NOR,me); 
        message_vision(YEL"$Nһ�����������������ȥ��\n"NOR,me);
        me->move(room);
        return 1;
} 
void reset()
{
        ::reset();
        set("alarm",0);
        
}   
