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
	set_name("[35m���֮��[2;37;0m", ({ "tianxuan sword", "sword" }));
	set_weight(11017);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[35m���֮��[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m�Ƴɣ��ض�ʮ����������Ǯ��[35m���֮��[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȷ���������[1;34m��������[2;37;0m��������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;34m����[2;37;0m [1;31mħ[2;37;0m:[35m��׼[2;37;0m [31m��[2;37;0m:[1;36m����[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 

���滹����һЩ���֣�
����:[1;31m��˫[2;37;0m ��ʯ:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ȷ[2;37;0m ������һЩ�� [1;32mȭ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "jqorzr");
		set("ownername", "��ȷ");
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 33);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 25);
    set("weapon_prop/qi", 31);
    set("weapon_prop/jing", 21);
    set("weapon_prop/jingli", 21);
    set("weapon_prop/damage", 35);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",7);
    set("wtypeE",0);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",8);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",5);
    

                set("skill", ([
                        "name": "cuff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 15);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(921);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";