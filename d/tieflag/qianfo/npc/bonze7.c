 inherit NPC;
int give_qin();
void smart_fight(); 
void create()
{
        set_name("����", ({ "yunming" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("long", "�����˹��������������������ֱ���ʦ\n");
        set("combat_exp", 3500000);
        set("attitude", "friendly");
        set("str",36);
        set("max_neili", 1000);
        set("neili", 1000);
        set("force_factor",90);
        set("max_atman",1500);
        set("atman",1500);
        
        set("no_busy",5);
                
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
            set_skill("parry", 120);
            set_skill("cloudstaff", 170);




            map_skill("force", "lotusforce");

       
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵��������ѧ������\n",
        }) );
        set("inquiry", ([
                "����" : (: give_qin :),
                "qiaozhong" : (: give_qin :),
        ]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
        carry_object(__DIR__"obj/zhongbook");
}
int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
} 
int give_qin()
{
        object obj;
if( !query("given"))
        {
command("say ��ѷ�������ȥ���ɣ���\n");
obj = new(__DIR__"obj/fezhong");
obj->move(this_player());
set("given",1);
        }
else
command("say �ҵķ����������ˣ�\n");
        return 1;
} 
void reset()
{
delete("given");
}  
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>1 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }
        who->perform_action("unarmed.qianshouqianbian");
        return;
}          
