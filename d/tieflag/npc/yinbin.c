 // yinbin.c
inherit NPC;
void create()
{
    set_name("����",({"yin bin","yin","bin"}));
    set("long","���������������ɴ����Լ��¶�������������������þ��ˣ�����������ҩ�����￴��\n");
    set("gender","Ů��");
    set("age",42);
    set("int",20);
    set("per",35);
    set("cps",20);
    set("jing",200);
    set("max_jing",200);
    set("eff_gin",200);
    set("max_qi",400);
    set("eff_qi",400);
    set("qi",400);  
    set("max_sen",500);
    set("jing",500);    
    set("eff_sen",500);
    set("combat_exp",50000);
    set_skill("force",100);
    set_skill("nine-moon-force",20);
    set_skill("unarmed",100);
    set_skill("nine-moon-claw",40);
    set_skill("nine-moon-steps",40);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("neili",1000);
    set("max_neili",1000);
    set("force_factor",10);
    map_skill("force","nine-moon-force");
    map_skill("unarmed","nine-moon-claw");
    map_skill("dodge","nine-moon-steps");
    set("attitude", "friendly");
    set("chat_chance",5);     
    set("chat_msg",({
          "�����۲���ת��Ц��������ֻ�����Եص����ˣ�����ƫƫ�����������\n",
          "����Ц���������Ҫ���ƿ���ɴ���㿴��ô����\n",
          }) ); 
    setup();
    carry_object(__DIR__"obj/redcloth")->wear();
    carry_object(__DIR__"obj/redjin")->wear();
}
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    command("lovelook");
    call_out("leave",10,me);
    return 1;
} 
void leave(object me)
{
    if (living(this_object()) && environment(me) == environment())
    {
      command("say ��Ҳ�����ˣ��������˽����أ�");
      message_vision("$N����һЦ�����˳�ȥ��\n",this_object());
      me->set_temp("mark/����",1);
      destruct(this_object());
    }
    else
      remove_call_out("leave");
}    
