inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("�ϻ���", ({"laohu jing", "jing"}));
        set("long", "һ�������ɷ����ϻ���������Ѫ���ڣ�Ҫ���˵����ӡ�\n");
        set("age", 30);
        set("attitude", "aggressive");
	set("bellicosity", 1000);
        set("gender", "����");
	set("class", "yaomo");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",1000);
        set("max_jing", 900);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 50);
        set("combat_exp", 350000);
  set("combat_exp", 100000);


	set("eff_dx", -150000);
        set("nkgain", 400);

        set("neili", 500);
        set("max_neili", 500);
  
	set_weight(5000000);
        setup();
        initlvl((500+random(500)),52);
	carry_object("/d/obj/weapon/blade/blade")->wield();
}
int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{

        this_object()->add("time", 1);

        if( (int)this_object()->query("time") >= 10 ) {
        message("vision",name() + "һ������������ݴ��в����ˡ�\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

void die()
{
	object skirt, env;
        if( environment() ) {
        message("sound", "\n�ϻ������Ʋ��ã���Ȼ�����Լ���Ƥ�������һ���ϻ�ģ����\n", environment());

		seteuid(getuid());
		if( skirt=new("/d/qujing/bibotan/obj/hupiqun") )
		skirt->move(environment());
		message("vision", "������һ���֮��������һ������������ݴ��в����ˡ�\n",environment());
        }
	env=environment(this_object());
	env->set("done", 1);
        destruct(this_object());
}
