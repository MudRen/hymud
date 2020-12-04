#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;37mº®±ùÖ®¶Ü[2;37;0m", ({ "general shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ãæ");
		set("long", @LONG
Ä§¸¤Ö®¶Ü[2;37;0mÕâÊÇÒ»ÃæÓÉÊ®·Ö¼áÓ²µÄ[1;32mÂÌÊ¯[2;37;0m¼ÓÉÏ[1;33mÜÑÂé[2;37;0mÖÆ³É£¬ÖØÁù½ï¶şÁ½°ËÇ®µÄ[1;37mÄ§¸¤Ö®¶Ü[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´Ê®·Ö¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[33mºÜ¸ß[2;37;0m [1;31mÄ§[2;37;0m:[33mºÜ¸ß[2;37;0m [1;33m½ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m [36mÄ¾[2;37;0m:[33mºÜ¸ß[2;37;0m [1;34mµç[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[33mºÜ¸ß[2;37;0m ÇÉÖÆ:[33mÒ»°ã[2;37;0m 
ÉÁµç:[33mÒ»°ã[2;37;0m 

ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·ÉÑ©[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÖ¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "flysnow");
		set("ownername", "·ÉÑ©");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 6);


    set("armor_prop/armor", 134);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",8);
    set("wtypeI",4);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";