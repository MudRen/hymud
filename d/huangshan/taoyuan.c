 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Դͤ");
        set("long", @LONG
ͤ�ӽ����һ���ı�Ե��ͤ�Ӳ����������һ�������ȥ�Ƕ��͵��±ڣ�
һ��С����������������±��ϣ����䲻�󣬵������̸���������±ڣ��ɼ����
�Ѿá���ͤ���֮�����ڿ��Ծ������ͻ�ɽ������֮һ�ġ������١���Զ����ȥ����
����й��ǡ���Ǹ����֣�ɷ����Ȥ��
LONG
        );
        set("exits", ([ 
                "northeast"  : __DIR__"taohua",
        ]));
    set("objects", ([
        __DIR__"npc/girl": 1,
    ]) );
        set("marks/climb", 0);
    set("indoors", "huangshan");
    set("coor/x",-535);
        set("coor/y",-515);
        set("coor/z",20);
        setup();
} 
void init() {
        add_action("do_climb", "climb");
} 
void tie_notify(object obj, int i) {
        
        object me;
        
        me = this_player();
        
        message_vision("$N��" + obj->name() + "����ͤ�������ϣ����ӵ�һͷ���������¡�\n", me);
        set("long", @LONG
ͤ�ӽ����һ���ı�Ե��ͤ�Ӳ����������һ�������ȥ�Ƕ��͵��±ڣ�
һ��С����������������±��ϣ����䲻�󣬵������̸���������±ڣ��ɼ����
�Ѿá�ͤ�ӿ��±ڵ������ϰ���һ�����������ӵ�һͷ���������¡�
LONG 
   );
        destruct(obj);
        set("marks/climb", 1);
} 
int do_climb(string arg) {
    object obj, me;
    int i;
 
    me = this_player();
    if(!arg || arg=="") return notify_fail("��Ҫ��ʲô��\n");
    if(me->is_busy()) return notify_fail("������æ��\N");
    if(arg == "down" || arg == "����" || arg == "�ͱ�"){
                if(query("marks/climb") == 1) {
                        me->start_busy(2);
            message_vision("$Nץ�����ӣ����ȵ�˳���ͱ�������ȥ��\n", me);
                call_out("fliping",2,me);
            } else {
                message_vision("$N̽ͷ�����¿��˿������ɵ�ҡ��ҡͷ��\n", me); 
        }
    }                    
        return 1;
} 
int fliping(object me)
{
        if( !me->is_ghost()) {   
        me->move(__DIR__"tree");
        message_vision("$N˳�Ŵ��µ����ӣ����ȵ�����������\n", me);
        }
        return 1;
} 
void reset(){
        ::reset();
    set("long", @LONG
ͤ�ӽ����һ���ı�Ե��ͤ�Ӳ����������һ�������ȥ�Ƕ��͵��±ڣ�
һ��С����������������±��ϣ����䲻�󣬵������̸���������±ڣ��ɼ����
�Ѿá���ͤ���֮�����ڿ��Ծ������ͻ�ɽ������֮һ�ġ������١���Զ����ȥ����
����й��ǡ���Ǹ����֣�ɷ����Ȥ��
LONG
    );  
        set("marks/climb", 0);
}       
