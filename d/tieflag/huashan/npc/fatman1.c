 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();
 
void create()
{
        set_name("�ֹ���", ({ "fat man", "man" }) );
        set("gender", "����" );
        set("age", 32);
        set("str", 30);
        set("int", 40);
        set("cor", 40);
        set("cps", 1);
    set("long",
"���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����
�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������
�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ�� \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
  set("str", 50);
        set("dex", 50);
        set("con", 50);
        set("int", 50);
        set("per", 50);
        set("per",23);
        set("tianyu_1",1);
        set("jing", 20000);
        set("eff_jing", 20000);
        set("max_jing", 20000);        
        set("qi", 22000);
        set("eff_qi", 22000);
        set("max_qi", 22000);
        set("max_jingli", 22000);
        set("neili", 40000);
        set("max_neili", 40000);
        set("max_jingqi",1000);
        set("combat_exp", 9000000);
        set_skill("dodge",300);
        set_skill("cuff",320);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",380);

         set_skill("wuxing-dun",280);
        set_skill("shayi",280);
         set_skill("aikido",280);
         set_skill("shayi-xinfa",320);
        set_skill("shiren-jianfa",280);
        set_skill("shiren-quanfa",280);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",180);

set_skill("xuanhualiu-quanfa",280);
set_skill("ninjitsu",380);
set_skill("ittouryu",380);
set_skill("enmeiryu",380);
set_skill("hand",320);
        set_skill("literate",250);
        map_skill("blade", "ittouryu");
        map_skill("force", "shayi-xinfa");
        
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "shiren-jianfa");
        
        map_skill("hand", "enmeiryu");
        map_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("cuff", "xuanhualiu-quanfa");
	prepare_skill("hand", "enmeiryu");
        

         set("chat_chance_combat", 98);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "hand.mukuha" :),
                (: perform_action,"hand.shiden" :),
                (: perform_action, "hand.shimon" :),  
                (: perform_action, "hand.chuyao" :), 
                (: perform_action, "hand.linfengguilong" :), 		
                (: perform_action, "blade.gobankiri" :), 
                (: perform_action, "blade.hyakki" :), 
                (: perform_action, "blade.daoshen" :), 
                (: perform_action, "blade.shiwanshenmo" :), 
                (: exert_function, "berserk" :),
                (: exert_function, "durup" :),
                (: exert_function, "shayi" :),
                (: exert_function, "shenzu" :),	
                (: exert_function, "powerup" :),		
        }));
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ֹ��ӳ�ü������̾����������������ô������ȥ����ô�����أ���\n",
                "�ֹ��Ӻ�Ȼ����̾�˿�������������֪�������һ�������ˣ��������˲��١���\n",  
                "�ֹ�����һ˫�ְ����ۣ������ü��õ��֣�����һ����ͷ�������ֳ�������
�ı��飬������ͷ����ŵ��廨�⣬Ȼ��һ��ҧ��ȥ��\n",
                "�ֹ�����������������֪��ô�ģ�һֻ�ɹ��Ĳ�Ӭ���ڵ��ϡ�\n",
        }));

        setup();
        carry_object(__DIR__"obj/fatcloth")->wear();
        carry_object(__DIR__"obj/chickbone");
//        carry_object("/obj/armor/boots")->wear();
        carry_object("/d/feitian/npc/blackblade")->wield();
        carry_object(__DIR__"obj/mantou");
} 
void init(){
   ::init();
        add_action("do_look", "look");
        add_action("do_kill", "kill");
} 
int do_look(string arg) {
        if(arg == "fat man" || arg == "man"){
                write("���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����\n");
                write("�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������\n");
                write("�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ��\n");
                write("��������Լ��ʮ���ꡣ\n");
                write("������"+WHT"�Ŀ�����"NOR+"���书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
                write("�����������������۷�״̬��\n");
                write("����"+BLU"�����"NOR+"(Silk cloth)\n");
                return 1;
        }
        return 0;
        
} 
int accept_object(object me, object ob){
        if(ob->query("food_remaining")){
                message_vision("$N�ӹ�" + ob->name()+"��ϸ�ĳ��˽�ȥ��Ȼ�������̾�˿�����\n", this_object());
                if(ob->query("name") == YEL"�л��Ӽ�"NOR){
                        message_vision("$N���ĵ�̾�˿���������\n", this_object());
                }
                return 1;
        }
        if(ob->query("name") == "������" || ob->query("name") == "������" ){
                if (ob->query("id") == "go piece"){
                message_vision("$N�ð��۵��ֽӹ�"+ob->query("name")+"��ͷ̾����������������ԭ�İ���Ҳ���ʶ��һ����\n",
                                this_object());
                message_vision("��Ȼ����ô����,�����㼸��Ҳ���ⲻȥ����\n", me);        
                me->set("free_learn/perception", 1);
                return 1;
                }
                return 0;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/perception")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$NЦ���еĶ�$n˵��������һ���ܳ���ֻ�����ǽл��Ӽ���ζ���治����\n", 
                        this_object(), ob);
        else 
        message_vision("$N���˸����ã�Ц���еĶ�$n˵���������������ˣ�ֻ�������黭����̸����֮�¡���\n", 
                        this_object(), ob);             
                return 0;
    }
} 
int do_kill(string arg) {
        if(arg == "fat man" || arg == "man"){
        message_vision("$Nͬ��ؿ���$nһ��˵������������һ������˭�ˡ�\n",this_object(),this_player());
        message_vision("$N֣�صظ���$n�����ҽ�"+HIW"����"NOR+"������Ѽ��"+HIW"��"NOR+"�����ӵ�"+HIW"��"NOR+"��������\n"NOR,this_object(),this_player());
        message_vision("���������ʼ�,��֪�Ķ�����һ������ͷ��ž���ش���$N�ļ羮Ѩ�ϡ�\n",this_player());
        this_player()->start_busy(1);
        this_object()->kill_ob(this_player());
        this_player()->kill_ob(this_object());  
        return 1;
        }
        return 0;
}   
int wieldblade()
{
command("unwield all");
command("wield blade");
perform_action("blade.banlanwushi");
command("unwield blade");
command("wield bone");
return 1;
}