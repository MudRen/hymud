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
	set_name("[1;31m����[2;37;0m", ({ "shentong sword", "sword" }));
	set_weight(16129);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[1;31m�����ͨ������Ҫƽ�ƣ���Ҫ���У����۹˼⣬���������ȣ�
��������Ȼ����������࣬������ͣ�磬���绨��������ֶ���
[2;37;0m����һ�����൱��Ӳ��[37m����[2;37;0m�Ƴɣ�����ʮ���������Ǯ��[1;31m��֮ͨ��[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������൱����������[1;34m��������[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m��˫[2;37;0m [36mľ[2;37;0m:[1;36m����[2;37;0m [31m��[2;37;0m:[1;35m����[2;37;0m [1;35m��[2;37;0m:[1;35m����[2;37;0m 

���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[32m�ֲ�[2;37;0m ��ʯ:[34mϸ��[2;37;0m ����:[31m����[2;37;0m 
����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mŷ������[2;37;0m ������һЩ�� [1;32mצ��[2;37;0m ���ļ��ɡ�

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "green");
		set("ownername", "ŷ������");
		set("value", 25000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",35);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 27);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 66);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 59);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",12);
    set("wtypeB",7);
    set("wtypeC",0);
    set("wtypeD",11);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 16);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_sword(731);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";