 // hu.c
inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("�ֹ���", ({ "fat man", "man" }) );
        set("gender", "����" );
        set("age", 32);
        set("str", 30);
        set("int", 40);
        set("cor", 40);
    set("long",
"���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����
�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������
�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ�� \n"
    );
        set("force_factor", 100);
        set("combat_exp", 7000000+random(3000000));
        set("attitude", "friendly");
        set_skill("move",100);
        //set_skill("perception", 150);
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ֹ��ӳ�ü������̾����������������ô������ȥ����ô�����أ���\n",
                "�ֹ��Ӻ�Ȼ����̾�˿�������������֪�������һ�������ˣ��������˲��١���\n",  
                "�ֹ�����һ˫�ְ����ۣ������ü��õ��֣�����һ����ͷ�������ֳ�������
�ı��飬������ͷ����ŵ��廨�⣬Ȼ��һ��ҧ��ȥ��\n",
        }));
        set("skill_public", 1);
        setup();
        carry_object(__DIR__"obj/fatcloth")->wear();
        carry_object("/d/feitian/npc/blackblade")->wield();
        carry_object(__DIR__"obj/mantou");
} 
void init(){
        ::init();
        add_action("do_look", "look");
} 
int do_look(string arg) {
   if(arg == "fat man" || arg == "man"){
                write("���������Ÿ��ˣ�����˲����֣������ֵ�����ޱȣ������������Ҵ�����\n");
                write("�����ͣ���������ֱ�����ǿ��ķ����⣬���Ŵ��ȴ���Ǹ�������������\n");
                write("�޲��ð�ȫ���ҵ������������������±��˲�֪������Ǯ��\n");
                write("��������Լ��ʮ���ꡣ\n");
                write("�����Ĳ��ֲ��ݣ��书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
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
        if(ob->query("id") == "piece" && ob->query("name") == "������" ){
                message_vision("$N�ð��۵��ֽӹ�"+ob->query("name")+"��ͷ̾����������������ԭ�İ���Ҳ���ʶ��һ����\n",
                                this_object());
                message_vision("$N���Ը���������ѧϰ�������֮������\n", me); 
                me->set("fear_learn/perception", 1);
                return 1;
        }
        return 0;
} 
int recognize_apprentice(object ob){
    if(ob->query("free_learn/perception")) {
        return 1;
    } else {
        message_vision("$NЦ���еĶ�$n˵��������һ���ܳ���ֻ�����ǽл��Ӽ���ζ���治��\n", 
                        this_object(), ob);
                return 0;
    }
}      
