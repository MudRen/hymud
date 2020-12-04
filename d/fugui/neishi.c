#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
�������Ϲ�����Ѽ�ĳ�����Ҳ������Ϣ˯���ĵط�����Ȼ���е������Ǻ���
���壬���̰��ı�Ѭ�úڵø������Ƶģ�һ��������Ϲ�����Ѽ����̨����ʱƮ��
�����̲�ס����ˮ����ζ����̨�ϰ��ż�ֻ��������������ľͷ���ӡ�
LONG); 
        set("be_ambushed",1);
        set("type","indoors");
        set("exits",([
                "east":__DIR__"duckshop",
        ]) );
        set("objects", ([
                __DIR__"obj/zaotai" : 1,
        ]) );
        set("coor/x",-600);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
int reset()
{
        object feng;
        ::reset();
        set("be_ambushed",1);
        if ( feng = present("feng qiwu", this_object())) {
                destruct(feng);
        }
} 
void init()
{
        object me;
        if(userp(me=this_player()))
        {
                remove_call_out("entering");
                call_out("entering",1,me);
        }
   add_action("do_get","get");
} 
int entering(object me)
{
        object con, bot,zb,ky,ky1;
        object *inv;
        int i,j,k;
        object ob;     
        if( userp(me) && (ob = present("feng qiwu", this_object())) && me->query_temp("fugui_mai_showyaopai") ) 
        {
                con = present("zaotai", this_object());
                inv = all_inventory(con);
                if( !sizeof(inv))
                {
                        bot  = new(__DIR__"obj/tieguo");
                        ky1  = new(__DIR__"obj/kaoya1");
                        zb=new(__DIR__"obj/xing");
                        zb->move(ky1); 
                        zb=new(__DIR__"obj/pearl");
                        zb->move(ky1); 
                        zb=new(__DIR__"obj/yuxi");
                        zb->move(ky1); 
                        zb=new(__DIR__"obj/pin");
                        zb->move(ky1); 
                        zb=new(__DIR__"obj/zhubao");
                        zb->move(ky1); 
                        j=random(5);
                        for (i=0;i<j;i++)
                        {       
                                ky  = new(__DIR__"obj/kaoya");
                                ky->move(bot); 
                        }
                        ky1->move(bot);
                        k=random(5);
                        for (i=0;i<k;i++)
                        {       
                                ky  = new(__DIR__"obj/kaoya");
                                ky->move(bot); 
                        }
                        bot->move(con);
           }
                message_vision(HIR"�ڰ���һ����ͻȻ�����������������ӷ�����ý���ݣ���ֱ�޷�
���������ݣ�һ�±��ס$N�����ţ�����������վס������Ҫ$N������
�����Ҿ��Ƿ����ࡣ�������ڵ�Ϧ��˵����֪���кη�����\n"NOR,me);
               
                me->start_busy(3);
                me->delete_temp("fugui_mai_showyaopai");
                ob->kill_ob(me);
                me->kill_ob(ob);
        }       
        return 1;
} 
int do_get(string arg)
{
        object jin, jia, fig;
        object me;
        string what,where;
        me=this_player();
        if(!arg) return 0;
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        
        if (present("jin shizi",environment(this_player()))
                        || present("jia gun",environment(this_player()))
                                || present("figure",environment(this_player())))
        {
                write("���ڻ�������Ѽ�ӵ�ʱ�򣡣�\n");
                return 1;
        }
        
        if(where == "zaotai" || where == "��̨" )
        {
                if (present("feng qiwu", this_object())) 
                {
                        message_vision("�������ݺݵص���$Nһ�ۣ�$N�ŵ����ϾͰ������˻�ȥ��\n\n"NOR,me);
                        return 1;
                }
                if (!this_player()->query_temp("marks/fugui_killed_feng"))
                {
                        write("��Ѽ���㰡��������ֻ������\n");
                        return 1;
           }
                if (query("be_ambushed"))
                {
                        jin =find_living("jin shizi");
                        jia =find_living("jia gun");
                        fig =find_living("mei rujia");
                        if (me && jin && jia && fig)
                        {
                                set("be_ambushed",0);
                                jin->set("chat_chance",0);
                                jia->set("chat_chance",0);
                                message_vision(CYN"$NͻȻ����������˴��һ����������������$N�ŵ����ϾͰ������˻�ȥ��\n\n"NOR,me);
                                if(environment(me) == this_object())
                                {
                                        message_vision("$Nһ�仰��˵���Ҵ�ææ���뿪�ˡ�\n",jin);
                                        jin->move(this_object());
                                        message_vision("$N���˽�����\n",jin);
                                        message_vision("$Nһ�仰��˵���Ҵ�ææ���뿪�ˡ�\n",jia);
                                        jia->move(this_object());
                                        message_vision("$N���˽�����\n",jia);
                                        message_vision("$Nһ�仰��˵���Ҵ�ææ���뿪�ˡ�\n",fig);
                                        fig->move(this_object());
                                        message_vision("$N���˽�����\n",fig);
                                }
                                call_out("event",3,jin,jia,fig,me,0);
                                return 1;
                        }
                        return 0;
                }
        }
        return 0;               
} 
void event(object jin,object jia,object fig,object me,int count)
{
        object room;
        room = this_object();
        
        if (present(jin,room) && present(jia,room) && present(fig,room) && present(me,room))
        {
                if (count == 0)
           {
                
                        jin->ccommand("say �ܺã����ڰ����������ˡ�");
                        jia->ccommand("sigh");
                        jia->ccommand("say ԭ�����Ϲ���Ƿ����࣬����û���뵽��");
                        jin->ccommand("say �����Ƿ������ͬ��������¡�");
                }
                else if (count == 1)
                {
                        me->ccommand("?");
                        me->ccommand("say �ѵ��������롣����");
                }
                else if (count == 2)
                {
                        jia->ccommand("grin jin");
                        jia->ccommand("say ֻҪ��һ������˭֪�������Ѿ����˷�����İ��ӣ�");
                        jin->ccommand("say ���������µ���ô������鱦�������Կ��԰�Ȼ�����ˡ�");
                        jia->ccommand("say С�ӣ�ֻ�������������ˡ�");
                        jin->ccommand("say �����ɡ�");
                        jin->set("immortal",1);
                        jia->set("immortal",1);
                        jin->set("force_factor",50);
                        jia->set("force_factor",100);
                        jin->kill_ob(me);
                        jia->kill_ob(me);
                        me->start_busy(10);
                }
                else if (count == 3)
                {
                        jin->ccommand("say �Ϲ�������ô�������֣�");
                }
                else if (count == 4)
                {
                        message_vision(HIR"$N��Ȼ�����İν�����ֻ����ǰһ������ʨ�Ӻͼй������ѵ��¡�\n"NOR,fig);
                        jin->remove_all_killer();
                        jia->remove_all_killer();
                        jin->ccommand("say �㡣������Ȼ������");
                        message_vision(CYN"$N���ģ��ۣ���һ���³�һ̲��Ѫ����\n"NOR,jin);
                }
                else if (count == 5)
           {
                        message_vision(CYN"$N�����˵�������Ҳ����Ϲ��󡣡�\n"NOR,fig);
                        message_vision(CYN"$N˵�������ҷ����ᶽ����֮�����������������������Ƿ��в�����Ϊ����\n"NOR,fig);
                }
                else if (count == 6)
                {
                        message_vision(CYN"$N˵������������������������ˣ���Ҫ������Ѻ�����ˡ���\n"NOR,fig);
                        message_vision(HIY"������һ�����Ž�ʨ�ӣ�һ�����żй���ת����ȥ��\n"NOR,me);
                        if(!me->query("m_success/����˫ȫ׽���"))
                        {
                                me->set("m_success/����˫ȫ׽���",1);
                                me->add("score",200);
                                me->add("potential",500);
                                me->add("combat_exp",1000);
                                tell_object(me,"�㱻�����ˣ�\nһǧ�㾭��\n��ٵ�Ǳ��\n���ٵ��ۺ�����\n\n");
                        }
                        destruct(fig);
                        destruct(jin);
                        destruct(jia);
                }
                else 
                        return;
        }
        else
        {
                if(jin) {
                                message_vision(HIY"$N��Ц��ȥ��\n"NOR,jin);
                                destruct(jin);
                        }
                if(jia) {
                                message_vision(HIY"$N��Ц��ȥ��\n"NOR,jia);
                                destruct(jia);
                        }
                if(fig) {
                                message_vision(HIY"$N̾�˿�����ת����ȥ��\n"NOR,fig);
                                destruct(fig);
                        }
                return;
        }
        call_out("event",random(5),jin,jia,fig,me,count+1);
   return;
} 
int valid_leave(object me)
{
        object room,jin,jia,fig;
        object mai;
        room=environment(me);
        if(mai=present("mai laoguang",room))
        {
                return notify_fail("��������ס�����ȥ·��\n");
        }
        if(jin=present("jin shizi",room))
        {
                message_vision("$N��ס�����ȥ·�������ӣ�û��ô���ף���\n",jin);
                return notify_fail("�ȹٲ���갸���߰ɣ�\n");
        }
        if(jia=present("jia gun",room))
        {
                message_vision("$N��ס�����ȥ·�������ӣ�û��ô���ף���\n",jia);
                return notify_fail("�ȹٲ���갸���߰ɣ�\n");
        }
        return 1;
} 
