 inherit NPC;
#include <ansi.h>  
void create()
{
    set_name("����ү",({"wu sanye","wu","sanye"}));
    set("title",HIR"����"NOR);
    set("long","��ү���䣬����ɽ���������û�˸ҽ��������֣��ҽе��˵ڶ����ʲô���ֶ���
�������ˡ�����үʲô�����ɣ�ֻ����̫ƽ����ط���һ�������ġ���\n");
    set("gender","����");
    set("age",52);
        set("combat_exp", 9000000);
        set("attitude", "friendly");    
         
        set("max_atman", 600);
        set("atman", 600);
        set("max_mana", 600);
        set("mana", 600);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",130); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
             
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "����ү΢Ц���������м����������Ǹ������ˡ������������˶�����������",
                "����ү���ͷ̾Ϣ�ŵ���Ů�����ǱȽ϶��ɵģ���������������Ů�ˣ���һֱ��\n��Ϊ��Ҫɱ��������",
        }) );

        setup(); 
        set_skill("yijinjing",200);
        set_skill("iron-cloth",200);
        map_skill("iron-cloth","yijinjing");
        carry_object(__DIR__"obj/bluecloth2")->wear();
   
}  
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player())) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object *inv;
        int pass;
        
        if( !ob || environment(ob) != environment()) return;
        
        if (ob->query("parrot/����") && ob->query("parrot/������ҵ�����")
                && ob->query("parrot/��ʯ������") && ob->query("parrot/ʬ�������")
                && ob->query("parrot/����Ѫū"))
                pass=1;
        
        if( pass && !ob->query_temp("parrot/����ү��ɱ") && !ob->query("parrot/����ү")) {
                message_vision(CYN"$N�����ǳǳ����һ�ڶ�$n�������㵽�������Ű��죬���ж�����Ҫɱ�㣿��\n",this_object(),ob);
                message_vision(CYN"$N�ֵ�������ʵ����ֻ��һ����--������Ȼ��Ҫɱ�㣬��ɱ���������
�������쾭������¡���\n",this_object());
                message_vision(CYN"$N�����Ľ��ŵ������ҿ��԰���ס���Ļ���������İ������������ʱ�̣���
��ϰ�߾��������㣬���Ƿ�Ҫ�Ұ����æ��\n",this_object());
           tell_object(ob,HIY"���������򡡣���󣯣� \n"NOR);
                ob->set_temp("sanye/answer_person",1);
                ob->set_temp("parrot/����ү��ɱ");
                return;
        }
}   
int do_answer(string arg)
{
        object who,key;
        int i, gotit;
        
        who=this_player();
        if(!who->query_temp("sanye/answer_person")) return 0;
        if (who->query_temp("sanye/answer_person")) {
                if(arg=="yes")
                {
                        message_vision(CYN"$N���д�ϲ�����ղ�����������ү���˵�ͷ��\n"NOR,who);
                        message_vision(CYN"$N�Ǻ�һЦ��������$n����˵�˼��仰��\n",this_object(),who);
                        tell_object(who,WHT"�����������ߣ��ɿ����ׯ��ǽ���š�\n"NOR);
/*                      key=new(__DIR__"obj/key");
                        if (key) key->move(this_object());
                        command("give key to "+who->get_id());*/
                        who->delete_temp("sanye/answer_person");
                        who->set("parrot/����ү",1);
                        return 1;       
                }
                if(arg=="no"){
                        message_vision(CYN"$N̾��������������˵�Ļ��������е��������\n"NOR,who);
                        message_vision(CYN"$N������ֻ��ϧ��һ���Ǹ���������ˡ���\n"NOR,who);
                        message_vision(YEL"$N����һ�µ���������ϣ����úõ��ٿ���һ�¡���\n"NOR,this_object());
                        who->delete_temp("answer_person");
                        who->set("parrot/����ү",2);
                        return 1;
                }
        }
}
