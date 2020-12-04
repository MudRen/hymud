 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "����");
        set("long", @LONG
���ʺ�С���ʽ����������������ģ�ֻ�ڶ�����һ��ͨ����С�ף��м�������
����һ��ʮ���������ͯ����ǰ����һ�����裬�����Ǽ�����ɵ���ͷ��һ������
��ˮ��Сͯ�����ؿ��ŵ��£��ƺ�û��ע�⵽���˽�����
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"camp",
                        ]));
        set("objects", ([
                __DIR__"npc/sima" : 1,
        ]));
        set("indoor","eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init() {
        
        add_action("do_loose", "loose");
} 
int do_loose(string arg){
        object me,ob;
        int i;
        me=this_player();
        ob=this_object();
        if (!arg && arg!="˾��С��"&& arg!="sima") {
                tell_object(me,"�����ʲô��\n");
                return 1;
        }
        if (!ob=present("sima",this_object())) {
                tell_object(me,"����û������ˡ�\n");
                return 1;
        }
   if (ob->query("loose")) {
                tell_object(me,"���Ѿ����⿪�ˡ�\n");
                return 1;
        }
        message_vision(YEL"$N���ֽ�˾��С�̴������Ͻ���������"NOR,me);
        message_vision(YEL"̾�˿�����$n˵������ش�ȥ�ɡ���\n"NOR,me,ob);
        message_vision(YEL"$N�ճմ����أ��ƺ�û������$n�Ļ���\n\n"NOR,ob,me);
        ob->set("loose",1);
        me->start_busy(4);
        switch (random(2)) {
                case 0: me->set("marks/bandit_result",1);
                        call_out("kill_self",1,me,ob);
                        break;
                case 1: if (me->query("PKS")<20) {
                                me->set("marks/bandit_result",1);
                                call_out("kill_self",1,me,ob);
                                break;
                                }
                        me->set("marks/bandit_result",2);
                        call_out("kill_me",1,me,ob);
                        break;
                }
        return 1;
} 
void kill_self(object me,object ob) {
        
        message("vision",WHT"�㷴��������ȥ��ͻȻ�������洫��һЩ���졣\n"NOR,this_object());
        message_vision(WHT"$Nת��һ����$n�ؿڲ���һ��ذ�׵�����ȥ��\n\n"NOR,me,ob);
        call_out("kill_self_2",1,ob);
        return;
} 
void kill_self_2(object ob) {
        message_vision(RED"$N��Ц��˵��лл�������ҡ���һֱ��Ϊ�Ҹ����Ǹ�Ӣ�ۣ�
û�뵽���������ҵ�Ѫ��ϴ�����ĳ���ɡ�\n"NOR,ob);
        ob->die();
} 
void kill_me(object me,object ob) {
        
        message("vision",WHT"�㷴��������ȥ��ͻȻ�������洫��һЩ���죬ֻ���Ŀ�һ������ͷһ������
��¶��һ�ض��С�"NOR,this_object());
   message_vision(WHT"$N��ͷ����$n���������������Լ����۾���\n\n"NOR,me,ob);
        call_out("kill_me_2",1,ob,me);
        return;
} 
void kill_me_2(object ob, object me) {
        object num;
        message_vision(RED"���Σ�$N��Ц��˵���Բ����Ҳ�������Ҹ��׵���Ӱ��Ҳ����ñ���
֪���ҵĹ�ȥ��$N�ֵ�����Ҳ���ؾ���ί������ɱ��"+chinese_number(me->query("PKS"))+"���У��ѵ���û��
һ���ǲ������ģ�\n\n"NOR,ob);
        me->receive_wound("qi",30000,ob);
        destruct(ob);
        return;
}        
