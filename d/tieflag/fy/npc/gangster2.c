 //written by Cheng Bao
// gangster.c 
inherit NPC;
void goaway();
void create()
{
        set_name("ɽ���ٷ�", ({ "gangster" }) );
        set("gender", "����" );
        set("age", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
��ɽ���ٷ������˰̣�����������һ���׺ݶ��Ե������ӡ�
LONG
);
        set("vendetta/authority",1);
        set("attitude", "heroism");
        set("bellicosity", 1500 ); 
        set("combat_exp", 10000); 
        set("chat_chance", 50);
        set("chat_msg", ({
                        (: goaway :),
        }) );  
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
              "ǿ�������Խ�Ϊ����������Ҫ��������\n",
              "ǿ���ߺ��������˲����ա�\n",
        }) ); 
        set("neili",5000);
        set("force_factor",20);
        set_skill("unarmed", 100);
        set_skill("blade", 160);
        set_skill("dodge", 140);
        set_skill("parry", 150);
        set_skill("demon-blade",120);
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
        setup();
        add_money("coin", 10); 
        carry_object(__DIR__"obj/guiblade")->wield();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object *ob;
        int i;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}    
