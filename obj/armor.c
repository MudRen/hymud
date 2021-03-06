#include <ansi.h> 
#include <armor.h>

inherit WEAPONTYPE;

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
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("WEAPON_SWORD", ({ "WEAPON_ID", "IDTYPE" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "unittext");
		set("long", @LONG
LONG_TITLE
LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ownertext");
		set("ownername", "ownernametext");
		set("value", valuetext);
		set("armor_prop/intelligence",inttext);
		set("armor_prop/strength",strtext);
		set("armor_prop/karey",kartext);
		set("armor_prop/percao",pertext);
		set("armor_prop/dexerity",dextext);
		set("armor_prop/constitution",context);
    set("armor_prop/dodge", dodgetext);
    set("armor_prop/parry", parrytest);
    set("armor_prop/attack", attacktest);


    set("armor_prop/armor", armortext);
    set("armor_prop/defense", defensetext);
    
    set("armor_prop/neili", neilitext);
    set("armor_prop/qi", qitext);
    set("armor_prop/jing", jingtext);
    set("armor_prop/jingli", jinglitext);
    set("armor_prop/damage", damagetext);

    set("wtypeA",wtypeAtext);
    set("wtypeB",wtypeBtext);
    set("wtypeC",wtypeCtext);
    set("wtypeD",wtypeDtext);
    set("wtypeE",wtypeEtext);
    set("wtypeF",wtypeFtext);
    set("wtypeG",wtypeGtext);
    set("wtypeH",wtypeHtext);
    set("wtypeI",wtypeItext);
    set("wtypeJ",wtypeJtext);
    set("wtypeK",wtypeKtext);
    set("wtypeL",wtypeLtext);
    
    
                set("skill", ([
                        "name": "skillnametext",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": skilllevtext,              
                ]) );		


		set("material", "default");
    set("sharpness", sharpnesstext);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";