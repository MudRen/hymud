#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���°���");
        set("long", @LONG
��ΧһƬ��ڣ������ˮ���а���������������磬������ë���
Ȼ���ֺ��������ж����ϤϤ�������������������Ե�����ֲ���ˮ����
���㲻֪Ҫͨ��δ������˫�ֺ��ҵ������ţ����г����˿־壬�и���
������Ҳ��ѽ���㲻���������Ϊʲôû��Щ�����Ķ���������
LONG
        );
        set("no_magic",1);
        set("coor/x",170);
        set("coor/y",-90);
        set("coor/z",-20);
        setup();
} 
void init()
{
        add_action("do_search", "search");
} 
int do_search(string arg)
{
        object me, room, book,frog; 
        me = this_player(); 
        switch (random(5)) {
                case 0:
                        tell_object(me,"���ںڰ����Ĵ�������ȴʲô��û�з��֡�\n");
                        break;
                case 1:
                        tell_object(me,RED "���ںڰ����Ĵ�������ͻȻ��о�����ʲô�������������ҧ��һ�ڡ�\n"NOR);
                        message_vision(YEL "$N�ںڰ��з���һ�����С�  ��....������......\n"NOR, me);
                        me->receive_damage("qi",50);
                        break;
                case 2:
                        tell_object(me, RED"��һ��С�Ļ�������ˮ�ֻ����һ�ɺܴ������������ȥ��\n"NOR );
                        tell_object(me,YEL"����е��в�����......ˮ�����������롣\n"NOR);
                        message("vision", "�ںڰ�����������ͨһ����ֻ��"+me->name()+"����Ӱ���Ա�һ���Ͳ����ˡ�\n" , environment(me),me);
                        me->receive_damage("jing",30);
                   me->move(__DIR__"well");
                        message("vision",me->name() + "ͻȻ��ˮ�����˳�����\n", environment(me),me);
                        break;
                case 3:
                        if(!me->query("m_success/�䵱���ŵ�����")) { 
                                tell_object(me,"���ںڰ��к���Ŀ�ĵ��Ĵ�������ͻȻ��о������ƺ������˸�Բ�Ķ�����\n");
                                tell_object(me,"��Ͽ�����������˻��\n", environment(me),me);
                                message("vision","�ںڰ���������һ��ϤϤ������������"+me->name()+"�ƺ������ﴧ��Щ������\n", environment(me),me);
                                book = new(__DIR__"obj/head");
                                book->move(me);
                                me->set("m_success/�䵱���ŵ�����",1);
                                me->add("score",1000);
                        }
                        else {
                                tell_object(me,RED "���ںڰ����Ĵ�������ͻȻ��о�����ʲô�������������ҧ��һ�ڡ�\n"NOR);
                                message_vision(YEL "$N�ںڰ��з���һ�����С�  ��....������......\n"NOR, me);
                                me->receive_damage("qi",50);
                        }
                        break;
                case 4:
                        if(!me->query_temp("well_frog")) { 
                                tell_object(me,"���ںڰ��к���Ŀ�ĵ��Ĵ�������ͻȻ��о������ƺ������˸��������С���\n");
                                if (me->query("combat_exp")>4000000) {
                                        tell_object(me,"��Ͽ�ץ���������˻��\n", environment(me),me);
                                        message("vision","�ںڰ���������һ��ϤϤ������������"+me->name()+"�ƺ������ﴧ��Щ������\n", environment(me),me);
                                        frog = new(__DIR__"obj/frog");
                                        me->set_temp("well_frog",1);
                                        frog->move(me);
                                } else 
                                        tell_object(me,"��һ��ûץ�����Ǹ��������������˳�ȥ��\n");
                        }       
                        else {
                                tell_object(me,RED "���ںڰ����Ĵ�������ͻȻ��о�����ʲô�������������ҧ��һ�ڡ�\n"NOR);
                                message_vision(YEL "$N�ںڰ��з���һ�����С�  ��....������......\n"NOR, me);
                                me->receive_damage("qi",50);
                        }
                        break;
                }
        return 1;
} 
void light_notify(object obj, int i)
{
        object *inv, me, room;
        int j;
        
        me = this_player();
        switch (i) { 
        case 0:
        message("vision","�ڰ��д������Ǽ������ߡ�ӵ�������\n" , environment(me), me);
        tell_object(me, obj->name() + "�ƺ���ˮ��ʪ�������ˡ�\n");
        break;
        case 1:
        message_vision(obj->name() + "�����Ĺ������˵ص���\n\n" , me);
        room = find_object(__DIR__"ltunnel");
        if(!objectp(room)) room=load_object(__DIR__"ltunnel");
        inv = all_inventory(this_object());
        for(j=0; j<sizeof(inv); j++) {
        inv[j]->move(room);
        }
        break;
        }
}   
