
 // hu.c
inherit NPC;
#include <ansi.h>
int wieldblade();

void create()
{
        set_name("�������", ({ "gongsun daniang", "daniang" }) );
        set("title", HIM"����Ů��"NOR);
        set("gender", "Ů��" );
        set("age", 37);
set("dex", 220);
        set("str", 220);
        set("int", 40);
        set("cor", 40);
        set("per", 80);
        set("cps", 20);
    set("long",
"���м��˹����ϣ����е��Ӵ��ҷ�����Ů����Ȼ���������Ƨ����ȴ��
Ȼ���ڸ��������޶�ɢ���ķ�ɧ�������ϵĲ������޶�Ŀ�����˼价��
˿�����������ϸ������������ͨ����Ů�ӡ� \n"
    );
        set("force_factor", 100);
        set("combat_exp", 700000+random(3000000));
        set("attitude", "friendly");


        set_skill("dagger",820);        
        set_skill("dodge",800);        

        set("skill_public",1);
        map_skill("dagger", "jianqi-dagger");
        map_skill("dodge", "chaos-steps");
        set("chat_chance", 10);
        set("chat_msg", ({
                "�������̾�˿��������ѵ��������������Ѿ�ʧ�����ᡣ��\n",
            "��������黨΢Ц˵�������ܰ����Ҹ����ô����\n",
                (: random_move :),
        }));
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: wieldblade  :),
        }) );
        setup();
        carry_object("/d/fugui/npc/obj/w_skirt2")->wear();
        carry_object("/d/tieflag/qianfo/npc/obj/silk")->wear();
        carry_object("/d/baiyun/shanliu/npc/obj/sworddagger")->wield();
} 
/*void init(){
   ::init();
        add_action("do_look", "look");
        add_action("do_kill", "kill");
} 
int do_look(string arg) {
        if(arg == "gongsun daniang" || arg == "daniang"){
                write("���м��˹����ϣ����е��Ӵ��ҷ�����Ů����Ȼ���������Ƨ����ȴ��\n");
                write("Ȼ���ڸ��������޶�ɢ���ķ�ɧ�������ϵĲ�����  ��Ŀ�����˼价��\n");
                write("˿�����������ϸ������������ͨ����Ů�ӡ�\n");
                write("��������Լ��ʮ���ꡣ\n");
                write("������"+YEL"��̬΢��"NOR+"���书����������"+HIR "��ɲ�"NOR+"�������ƺ����ء�\n");
                write("�����������������۷�״̬��\n");
                write("����"+RED"��������"NOR+"(Redskirt)\n");
                return 1;
        }
        return 0;
} */
int accept_object(object me, object ob){
        if (ob->query("name") == "��Ƥ���" ){
                if (ob->query("id") == "skinmask"){
                message_vision("$N�ӹ�"+ob->query("name")+"��Ц��˵����ԭ����Ҳ��ͬ�����ˡ���\n",
                                this_object());
                message_vision("��Ȼ��ˣ����ǲ���������������\n", me);        
                me->set("free_learn/dagger", 1);
                return 1;
                }
                return 0;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/dagger")) {
        return 1;
    } else {
        if (random(2))
        message_vision("$N����$n�黨΢Ц˵�������ܰ����Ҹ����ô����\n", 
                        this_object(), ob);
        else 
        message_vision("$N��$n���˸��򸣣������¼�Ц�ˣ���֪��������ʲô�ͽ��أ���\n", 
                        this_object(), ob);             
                return 0;
    }
} 

int wieldblade()
{
command("fox");
perform_action("dagger.jianwu");
command("sing2");
return 1;
}