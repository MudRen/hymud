// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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
	set_name("[31m����֮��[2;37;0m��", ({ "chungou staff", "staff" }));
	set_weight(9577);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
[31m������˧֮������֮�ܻӾ����򣬿˵���ʤ��
[2;37;0m����һ���ɼ�Ϊ��Ӳ��[1;37m����[2;37;0m�Ƴɣ���ʮ�Ž�һ����Ǯ��[31m����֮��[2;37;0m��
�ۺ�����[35m�������[2;37;0m ��������Ϊ����������[1;31m������˫[2;37;0m��������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;32mħ��[2;37;0m [31m��[2;37;0m:[31m����[2;37;0m [33m��[2;37;0m:[1;31m����[2;37;0m [1;35m��[2;37;0m:[1;31m����[2;37;0m 
[1;34m��[2;37;0m:[1;33m����[2;37;0m [37m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
����:[1;33m����[2;37;0m ����:[33m�ܸ�[2;37;0m ��Դ:[33m�ܸ�[2;37;0m 
����:[32m�ֲ�[2;37;0m 
����:[1;34m����[2;37;0m ����:[31m����[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);
		set("weapon_prop/intelligence",43);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",45);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 37);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 81);
    set("weapon_prop/jingli", 81);
    set("weapon_prop/damage", 60);

    set("wtypeA",9);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",6);
    set("wtypeE",15);
    set("wtypeF",15);
    set("wtypeG",0);
    set("wtypeH",16);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "��");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 21);

		set("wield_msg", "$N��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	
	init_staff(1274);
	setup();
}



#include "/obj/ritem/weaponzy.h";