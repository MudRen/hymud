// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[31mÁúÈªÖ®°µÆ÷[2;37;0m¡ï", ({ "longquan throwing", "throwing" }));
	set_weight(644);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö§");
		set("long", @LONG
[31mÁúÈªÈË¼ä¼«Æ·£¬ÎäÁÖÖÁ±¦£¡
[2;37;0mÕâÊÇÒ»Ö§ÓÉÎŞ±È¼áÓ²µÄ[1;37mÈíÒø[2;37;0mÖÆ³É£¬ÖØÒ»½ï¶şÁ½°ËÇ®µÄ[31mÁúÈªÖ®°µÆ÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;31m¿ªÔª´´ÊÀ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [1;34mµç[2;37;0m:[1;31m´´ÊÀ[2;37;0m [37mÌì[2;37;0m:[1;31m¿ªÔª[2;37;0m [40mµØ[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;36mÈË[2;37;0m:[1;36mÍêÃÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;31m»ÙÌì[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[33mºÜ¸ß[2;37;0m 
¾ø´ú:[33mºÜ¸ß[2;37;0m ÌìÔ¨:[33mºÜ¸ß[2;37;0m ÌåÁé:[35m±ê×¼[2;37;0m °×Ê¯:[31m¾«ÖÂ[2;37;0m ÖÜÌì:[35m±ê×¼[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m 

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
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",45);
		set("weapon_prop/percao",44);
		set("weapon_prop/dexerity",42);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 66);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 57);
    
    set("weapon_prop/neili", 53);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 77);
    set("weapon_prop/jingli", 77);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",8);
    set("wtypeD",13);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",14);
    set("wtypeI",13);
    set("wtypeJ",6);
    set("wtypeK",7);
    set("wtypeL",15);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 27);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	set_amount(1);
	init_throwing(1415);
	setup();
}



#include "/obj/ritem/weaponzy.h";