 inherit NPC;
void create()
{
        set_name("ɱ�˷�", ({ "killer bee" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("qi",700);
        set("eff_qi",700);
        set("max_qi",700);
        set("jing",300);
        set("eff_sen",300);
        set("max_sen",300);
        set("jing",300);
        set("eff_gin",300);
        set("max_jing",300);
        set("yes_carry", 1);
        set("long", "һֻ�׺ݵ�ɱ�˷䡣\n"); 
        set("limbs", ({ "ͷ��", "����", "β��", "�۾�" }) );
        set("verbs", ({ "bite" }) );
        set("attitude", "aggressive");
        set_skill("dodge", 100);
        set_skill("dodge",300);
        set("combat_exp", 29999);
        set("bellicosity", 300 );
        set("chat_chance", 20);
        add_temp("apply/damage",10+random(10));
        setup();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        add_action("do_get","get");
        }
} 
int do_get(string arg)
{
string what, where;
if(!arg) return 0;
if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
if((what== "all" || what== "potion") && (where=="bell" || where=="����"))
{
message_vision("$N�ݺݵ���$nһ�ۣ����˵���$n����������\n",this_object(),this_player());
this_object()->kill_ob(this_player());
this_player()->start_busy(2);
return 1;
}
}     
