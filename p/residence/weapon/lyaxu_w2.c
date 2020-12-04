// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;32mǧ����[2;37;0m", ({ "general club", "club" }));
	set_weight(5265);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
���֮��[2;37;0m����һ�����ޱȼ�Ӳ��[33m����[2;37;0m�Ƴɣ���ʮ��������Ǯ��[1;32m���֮��[2;37;0m��
�ۺ�����[31m��������[2;37;0m �������ޱȷ���������[32mˮ׼����[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;36m����[2;37;0m [36mľ[2;37;0m:[1;36m����[2;37;0m [32mˮ[2;37;0m:[34mϸ��[2;37;0m [1;35m��[2;37;0m:[35m��׼[2;37;0m 
[1;34m��[2;37;0m:[35m��׼[2;37;0m 
���滹����һЩ���֣�
����:[32m�ֲ�[2;37;0m ����:[36m����[2;37;0m ����:[36m����[2;37;0m ����:[36m����[2;37;0m ����:[33mһ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m����վ[2;37;0m ������һЩ�� [1;32m�м�[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "����վ");
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 15);
    set("weapon_prop/qi", 11);
    set("weapon_prop/jing", 11);
    set("weapon_prop/jingli", 11);
    set("weapon_prop/damage", 9);

    set("wtypeA",7);
    set("wtypeB",7);
    set("wtypeC",2);
    set("wtypeD",0);
    set("wtypeE",3);
    set("wtypeF",5);
    set("wtypeG",0);
    set("wtypeH",5);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_club(260);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";