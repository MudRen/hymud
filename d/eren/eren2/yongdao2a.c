 // SILENCER@FY4 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "Сʯ��");
        set("long",  @LONG
˵��ʯ������ʵֻ��ʯ����һ�鰼���ĵط�������ڹ�¡�˵����ֲ�����ָ��
�����ϲ�ͣ����ˮ�����������ھ���͸�ĵ��������²ȵ�����ӲӲ�Ķ�����˳��
����ȥ��������һ�����ã�ż�����м�ֻ���������ų��ɹ�����ڣ�ѹ�֣�ʹ
���̲�ס����������С�
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"yongdao2",
        ]));
        set("objects", ([
                __DIR__"obj/woodbarrel" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_scream", "scream");
        add_action("do_scream", "cry");
        add_action("do_scream", "jiao");
} 
int do_scream()
{
        object room, guard, me;
        me = this_player();
        if (guard=present("guardian",this_object()))
                return notify_fail("��������ǰ���е��ˣ�\n");
        remove_call_out("summon_guard");
//      call_out("summon_guard",3);
        me->start_busy(2);
   message_vision("\n$N����ס���еĿֻţ�ʧ������������������������������������\n",me);
        message_vision("�����ڶ����лص���ԶԶ�ش��˳�ȥ��\n\n"NOR,me);
        return 1;
} 
summon_guard() {
        
        object guard,room;
        
        room=find_object(__DIR__"yongdao3");
        if(!objectp(room)) 
                room = load_object(__DIR__"yongdao3"); 
        guard=present("guardian",room);
        
        if(!guard) {
                room=find_object(__DIR__"yongdao3a");
                if(!objectp(room)) 
                        room = load_object(__DIR__"yongdao3a"); 
                guard=present("guardian",room);
        }
        
        if (guard && !guard->is_fighting()) {
                guard->move(this_object());
                message("vision","δ����һ����Ӱ���˹�����\n",this_object());
                message("vision",guard->query("name")+"�ȵ�:��ʲô�ˣ�����\n",this_object());
        } else 
                message("vision","�����ã�һ�㶯��Ҳû�С�\n",this_object());
}        
        
                 
              
