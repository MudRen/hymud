 inherit NPC;
void use_poison(); 
void create()
{
        set_name("�޻���", ({ "huge serpent" }) );
        set("race", "Ұ��");
        set("age", 400);
        set("long", "�����޴��ޱȣ����������˶����������ϻ�ð��ŧѪ��\n");
        set("limbs", ({ "ͷ��", "����", "β��", "�ߴ�" }) );
        set("verbs", ({ "bite" }) );
        set_skill("dodge", 200);
        set("combat_exp", 2999999);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
        set_temp("apply/damage",100);
}
void use_poison()
{
        object *enemy, ob;
        string msg; 
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))]; 
        tell_object(ob,
"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
                ob->receive_wound("qi",40);
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !ob->query_temp("marks/cured_jia") ) {
                kill_ob(ob);
        }
}   
int cure_arong(object me)
{
 object room,obj;
 if(!query("cured") && me->query_temp("marks/cured_monk") &&
                       me->query_temp("marks/cured_jia") &&
                        !me->query_temp("marks/cured_snake")) {
 tell_object(me,"�޻������ϵĶ�����ŧѪ����ʼ��������ʧ�ˣ�����\n");
 tell_object(me,"�޻���̧��β����������ϲ��˲䣬�ƺ�������ĸ�л��\n");
 me->set_temp("marks/cured_snake",1);
 tell_object(me,"�޻����������³����ִ����������ӣ�Ȼ����β�;�ס����������һ�ף�����\n\n\n");
 tell_object(me,"�������ڿն��𣮣���Ŷร�����������\n\n\n");
 set("cured",1);
 obj = new(__DIR__"obj/pearl");
 obj->move(me);
 room = load_object("/d/chenxiang/wol2");
 me->delete_temp("marks");
 me->move(room);
 } 
 return 1; 
}   
