// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;33m̫��֮��[2;37;0m", ({ "taiji sword", "sword" }));
	set_weight(15796);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;33m̫���ߣ��޼�����������֮ĸҲ����֮��֣���֮��ϡ��޹��������������졣
�˸�����ν֮�ߣ���˳�˱�ν֮ճ��������Ӧ���������档��仯��ˣ���
��Ϊһ�ᣡ
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m�Ƴɣ�����ʮһ��������Ǯ��[1;33m̫��֮��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȷ���������[1;33m������ƥ[2;37;0m��������
������˼����ŷ��ţ�
[1;36m��[2;37;0m:[1;33m��ʥ[2;37;0m [1;31mħ[2;37;0m:[1;31m����[2;37;0m [1;33m��[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[1;36m����[2;37;0m [1;37m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
����:[1;31m����[2;37;0m ��Դ:[34mϸ��[2;37;0m 
����:[32m�ֲ�[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mСѩ��[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "xiaoxueer");
		set("ownername", "Сѩ��");
		set("value", 25000);
		set("weapon_prop/intelligence",40);
		set("weapon_prop/strength",40);
		set("weapon_prop/karey",26);
		set("weapon_prop/percao",40);
		set("weapon_prop/dexerity",56);
		set("weapon_prop/constitution",48);
    set("weapon_prop/dodge", 40);
    set("weapon_prop/parry", 56);
    set("weapon_prop/attack", 48);
    set("weapon_prop/armor", 56);
    set("weapon_prop/defense", 40);
    
    set("weapon_prop/neili", 48);
    set("weapon_prop/qi", 47);
    set("weapon_prop/jing", 47);
    set("weapon_prop/jingli", 47);
    set("weapon_prop/damage", 0);

    set("wtypeA",5);
    set("wtypeB",6);
    set("wtypeC",7);
    set("wtypeD",5);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",8);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",10);
    set("wtypeL",14);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(969);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";