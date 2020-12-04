 // zhuo.c
#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("׿����", ({"zhuo"}) );
        set("gender", "Ů��" );
        set("nickname", "����");
        set("age", 36);
        set("agi",30);
        set("no_arrest",1);
        set("per", 30);
        set("long",
                "����׿�����Ṧ������˫���ڱ��丳������������\n"
                );
        set("force_factor", 30);
        set("max_neili", 1000);
        set("neili", 1000);
        set("combat_exp", 999999);
        set("score", 10000);
    
        set_skill("dodge", 150);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("throwing", 100);

        set_skill("jingyiforce", 50);
        set_skill("feixian-steps", 100); 

        map_skill("force", "jingyiforce");
        map_skill("dodge", "feixian-steps");
        map_skill("dodge", "feixian-steps");
        
        set("chat_chance",1);
        set("chat_msg",({
                "׿����˵������������Ҫ���������߻�������ô�����Ǵ�����֮�ˣ���\n",
                "׿����˵������������ܰ������ǣ����ǾͿ��Եõ�ҹ�۵ı��أ����񹦱��䣡��\n",
           }) );
            setup();
        carry_object("/clone/misc/cloth")->wear();  
} 
void init()
{
    object me;
    ::init();
    if( interactive(me = this_player()) && !is_fighting() ) {
        remove_call_out("greeting");
        remove_call_out("feng_revive");
        if (me->query("marks/����") || me->query_temp("marks/����"))
        {
                command("say ��֪����Ķ�������"+RANK_D->query_self_rude(this_object())+"��ѵ��ѵ�㣡");
                this_object()->kill_ob(me);   
            return;
        }
        call_out("greeting", 1, me);
        add_action("do_accept","accept");
        return;
        }
}
void greeting(object me)
{
        object feng;
    if (feng=(present("feng jiuyou",environment()) )  )
        if (base_name(feng)==__DIR__"feng" )
                        command("say �����������ﱾ��ȡ��ҹ�۵ı��أ�û�뵽�����ĺ�Ȼ�߻���ħ��
�����Ը��������ǣ�ҹ�۵ı��ؾ�������ˡ�(accept yes/accept no)\n");
                
} 
int do_accept(string arg)
{
        object feng;
    object me;
        if (!arg || (arg!= "yes" && arg !="no")) return 0;
    me=this_player();
    if (me->is_fighting()) return 0;
    if (arg=="yes")
    {
           if (!feng=(present("feng jiuyou",environment()) )  ) 
        {
                command("sigh");
                        command("say û�з����ģ����������Ҳ�ǰ״");
                return 1;
                }
                if (base_name(feng)!=__DIR__"feng" )
                {
                        command("grin");
                        command("say �������Ѿ����ˣ����ǻ�Ҫ�����\n");
                        return 1;
                }       
        message_vision( YEL "$N��������$n�ĺ��ģ�������������\n"NOR,me,feng);
        me->start_busy(4);
                if (me->query("neili")<200)
                {
                        tell_object(me,"���������������Ү��\n");
                        return 1;
                        me->set("neili",0);
                }
        me->set("neili",0);
        me->set("marks/׿����",1);
        call_out("feng_revive",5,me,feng);
    }
    else
    {
      command("say ��֪����Ķ�������"+RANK_D->query_self_rude(this_object())+"��ѵ��ѵ�㣡");
      this_object()->kill_ob(me);
      me->kill_ob(this_object());
      if (!feng=(present("feng jiuyou",environment()) )  ) 
                return 1;
          if (base_name(feng)!=__DIR__"feng" )
                {
                        
                        feng->kill_ob(me);
                        me->kill_ob(feng);
                        return 1;
                }
                me->set_temp("marks/����",1);   
            call_out("feng_revive",20,me,feng);
    }  
    return 1;                                          
}
void feng_revive(object me,object feng)
{
        object lishi;
        object ark;
        object woman;
        int damage;    
    string myfile;
    myfile=base_name(this_object());
    //I do not want to specify an abs name of a room
    myfile=replace_string(myfile,"npc/zhuo","ark");
        if (environment(me)!=environment(this_object())) return;
        if (!living(feng)) return;
        destruct(feng);
        feng=new(__DIR__"feng2");
        feng->move(environment());
        message_vision("$N������һ������վ��������\n",feng);
        message_vision("$N�ȵ���������ʿ���ڣ���\n",feng);
        lishi=new(__DIR__"lishi");
        lishi->move(environment()); 
        message_vision("һ����ͭɫ�Ĵ󺺳�����$N����ǰ��\n",feng);
        if (!objectp(ark=find_object(myfile)))
                ark=load_object(myfile);
        if (!me->query_temp("marks/����"))
        {
        message_vision("$n˵��������ʿ������һ��֮���ɣ�\n",me,feng);
        message_vision("$n���һ����һ��ץס$N�����죬��$N���۶�ȥ��\n",me,lishi);
        me->move(ark);
    }
    else
    {
        message_vision("$N���һ�������ҹ��ۼҵ����£������ò��ͷ��ˣ���\n",feng);    
        feng->kill_ob(me);
        lishi->kill_ob(me);
        message_vision( HIR "����ʿ��Ȼ����һȭ������$N�������ϡ�\n"NOR,me);
        damage=500+random(750);
        me->receive_damage("qi",damage);
        COMBAT_D->report_status(me);
        message_vision( HIR "$N�����ӱ��������ߵķ���һ�������ɫ�Ĵ������þò��������֮����\n"NOR,me);
        me->move(ark);
        if((woman=present("old woman",ark)) && me->query("qi")>0 )
        {
                me->unconcious();
                call_out("me_revive",9,me,woman);
        }
    }
    return;
}        
void me_revive(object me,object woman)
{                                                                       
        if (me->query("marks/׿����")) return;
        me->revive();
        me->delete_temp("marks/����");
        if (me->query("marks/����")) return;
        if (environment(me)!=environment(woman)) return;
        message_vision("$N̾�����������ĺ��ӣ����������Ϊ�Ҷ�֪���ˡ���\n",woman);
        message_vision("$N˵������������һ��ά���ҵķ��ϣ��Ұ����ɡ�\n",woman);
        message_vision("$N����������ƣ�����$n������֮��...\n",woman,me);
        tell_object(me,"�����ȫ��������...\n");
        me->set_skill("force",me->query_skill("force",1)+3); 
        me->set("marks/����",1);
        return;
}    
