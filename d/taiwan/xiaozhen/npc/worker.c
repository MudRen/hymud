inherit NPC;
void create()
{   int i;
    i=random(3);
    if (i==1)
     set_name("ˮ��",({"shuishou"}));
    else if (i==2)
     set_name("���˹�",({"worker","banyu"}));
    else set_name("����",({"chuanfu"}));
    set("gender","����");
    set("age",18+random(30));
    set("combat_exp",10000*i);
    set("max_force",300*i);
    set("force",300*i);
    set_skill("unarmed",10*i+20);
    set_skill("force",10*i+20);
    set_skill("parry",10*i+20);
    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver",10*i+5);
}
    
         