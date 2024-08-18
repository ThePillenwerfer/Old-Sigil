/************************************************************************
**
**  Copyright (C) 2016  Kevin B. Hendricks, Stratford, Ontario, Canada
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#include <QString>
#include <QStringList>
#include <QHash>

#include "Misc/Landmarks.h"

Landmarks *Landmarks::m_instance = 0;

Landmarks *Landmarks::instance()
{
    if (m_instance == 0) {
        m_instance = new Landmarks();
    }

    return m_instance;
}


QString Landmarks::GetName(QString code)
{
    DescriptiveInfo rel = m_CodeMap.value(code, DescriptiveInfo() );
    return rel.name;
}


QString Landmarks::GetDescriptionByCode(QString code)
{
    DescriptiveInfo rel = m_CodeMap.value(code, DescriptiveInfo());
    return rel.description;
}


QString Landmarks::GetDescriptionByName(QString name)
{
    QString code = m_NameMap.value(name, QString());
    return GetDescriptionByCode(code);
}


QString Landmarks::GetCode(QString name)
{
    return m_NameMap.value(name, QString());
}

bool Landmarks::isLandmarksCode(QString code)
{
    return m_CodeMap.contains(code);
}

bool Landmarks::isLandmarksName(QString name)
{
    return m_NameMap.contains(name);
}

QStringList Landmarks::GetSortedNames()
{
    if (!m_sortedNames.isEmpty()) {
        return m_sortedNames;
    }

    foreach(QString code, m_CodeMap.keys()) {
        DescriptiveInfo rel = m_CodeMap.value(code);
        m_sortedNames.append(rel.name);
    }
    m_sortedNames.sort();
    return m_sortedNames;
}

const QHash<QString, DescriptiveInfo> & Landmarks::GetCodeMap()
{
    return m_CodeMap;
}

Landmarks::Landmarks()
{
    SetLandmarksMap();
    SetGuideLandMap();
}

QString Landmarks::GuideLandMapping(QString code)
{
  return m_GuideLandMap.value(code, QString());
}

void Landmarks::SetLandmarksMap()
{
    if (!m_CodeMap.isEmpty()) {
        return;
    }

    // See http://www.idpf.org/epub/vocab/structure/ (you need to look at previous versions to find the one
    // specific to the epub 3.0.1 spec

    QStringList data;
    data <<
        tr("Acknowledgments") << "acknowledgments" << tr("A passage containing acknowledgments to entities involved in the realization of the work.") <<
        tr("Afterword") << "afterword" << tr("A closing statement from the author or a person of importance to the story, typically providing insight into how the story came to be written, its significance or related events that have transpired since its timeline.") <<
        tr("Annotation") << "annotation" << tr("Explanatory information about passages in the work. Status: Deprecated") <<
        tr("Appendix") << "appendix" << tr("Supplemental information.") <<
        tr("Assessment") << "assessment" << tr("A test, quiz, or other activity that helps measure a student's understanding of what is being taught.") <<
        tr("Back Matter") << "backmatter" << tr("Ancillary material occurring after the main content of a publication, such as indices, appendices, etc.") <<
        tr("Bibliography") << "bibliography" << tr("A list of works cited.") <<
        tr("Body Matter") << "bodymatter" << tr("The main content of a publication.") <<
        tr("Chapter") << "chapter" << tr("A major structural division of a piece of writing.") <<
        tr("Colophon") << "colophon" << tr("A brief description usually located at the end of a publication, describing production notes relevant to the edition.") <<
        tr("Conclusion") << "conclusion" << tr("An ending section that typically wraps up the work.") <<
        tr("Contributors") << "contributors" << tr("A list of contributors to the work.") <<
        tr("Copyright Page") << "copyright-page" << tr("The copyright page of the work.") <<
        tr("Cover") << "cover" << tr("The publications cover(s), jacket information, etc.") <<
        tr("Dedication") << "dedication" << tr("An inscription addressed to one or several particular person(s).") <<
        tr("Division") << "division" << tr("A major structural division that may also appear as a substructure of a part (esp. in legislation).") <<
        tr("Epigraph") << "epigraph" << tr("A quotation that is pertinent but not integral to the text.") <<
        tr("Epilogue") << "epilogue" << tr("A concluding section that is typically written from a later point in time than the main story, although still part of the narrative.") <<
        tr("Errata") << "errata" << tr("Publication errata, in printed works typically a loose sheet inserted by hand; sometimes a bound page that contains corrections for mistakes in the work.") <<
        tr("Footnotes") << "footnotes" << tr("A collection of notes appearing at the bottom of a page.") <<
        tr("Foreword") << "foreword" << tr("An introductory section that precedes the work, typically not written by the work's author.") <<
        tr("Front Matter") << "frontmatter" << tr("Preliminary material to the main content of a publication, such as tables of contents, dedications, etc.") <<
        tr("Glossary") << "glossary" << tr("An alphabetical list of terms in a particular domain of knowledge, with the definitions for those terms.") <<
        tr("Half Title Page") << "halftitlepage" << tr("The half title page of the work which carries just the title itself.") <<
        tr("Imprimatur") << "imprimatur" << tr("A formal statement authorizing the publication of the work.") <<
        tr("Imprint") << "imprint" << tr("Information relating to the publication or distribution of the work.") <<
        tr("Index") << "index" << tr("A detailed list, usually arranged alphabetically, of the specific information in a publication.") <<
        tr("Introduction") << "introduction" << tr("A section in the beginning of the work, typically introducing the reader to the scope or nature of the work's content.") <<
        tr("Landmarks") << "landmarks" << tr("A collection of references to well-known/recurring components within the publication") <<
        tr("List of Audio Clips") << "loa" << tr("A listing of audio clips included in the work.") <<
        tr("List of Illustrations") << "loi" << tr("A listing of illustrations included in the work.") <<
        tr("List of Tables") << "lot" << tr("A listing of tables included in the work.") <<
        tr("List of Video Clips") << "lov" << tr("A listing of video clips included in the work.") <<
        tr("Notice") << "notice" << tr("Information that requires special attention, and that must not be skipped or suppressed. Examples include: alert, warning, caution, danger, important.") <<
        tr("Other Credits") << "other-credits" << tr("Acknowledgments of previously published parts of the work, illustration credits, and permission to quote from copyrighted material.") <<
        tr("Page List") << "page-list" << tr("A list of references to pagebreaks (start locations) from a print version of the ebook") <<
        tr("Part") << "part" << tr("A major structural division of a piece of writing, typically encapsulating a set of related chapters.") <<
        tr("Preamble") << "preamble" << tr("A section in the beginning of the work, typically containing introductory and/or explanatory prose regarding the scope or nature of the work's content") <<
        tr("Preface") << "preface" << tr("An introductory section that precedes the work, typically written by the work's author.") <<
        tr("Prologue") << "prologue" << tr("An introductory section that sets the background to a story, typically part of the narrative.") <<
        tr("Questions and Answers") << "qna" << tr("A question and answer section.") <<
        tr("Rear Notes") << "rearnotes" << tr("A collection of notes appearing at the rear (backmatter) of the work, or at the end of a section.") <<
        tr("Revision History") << "revision-history" << tr("A record of changes made to a work.") <<
        tr("Subchapter") << "subchapter" << tr("A major sub-division of a chapter.") <<
        tr("Title Page") << "titlepage" << tr("A page at the beginning of a book giving its title, authors, publisher and other publication information.") <<
        tr("Table of Contents") << "toc" << tr("A table of contents which is a list of the headings or parts of the book or document, organized in the order in which they appear. Typically appearing in the work's frontmatter, or at the beginning of a section.") <<
        tr("Volume") << "volume" << tr("A component of a collection.") <<
        tr("Warning") << "warning" << tr("A warning or caution about specific material. Status: Deprecated - Replaced by 'notice'.");


    for (int i = 0; i < data.count(); i++) {
        QString name = data.at(i++);
        QString code = data.at(i++);
        QString description = data.at(i);
        DescriptiveInfo rel;
        rel.name = name;
        rel.description  = description;
        m_CodeMap.insert(code, rel);
        m_NameMap.insert(name, code);
    }
}


void Landmarks::SetGuideLandMap()
{
    if (!m_GuideLandMap.isEmpty()) {
        return;
    }

    m_GuideLandMap[ "acknowledgements" ] = "acknowledgments";
    m_GuideLandMap[ "acknowledgments"  ] = "acknowledegments";
    m_GuideLandMap[ "bibliography"     ] = "bibliography";
    m_GuideLandMap[ "text"             ] = "bodymatter";
    m_GuideLandMap[ "bodymatter"       ] = "text";
    m_GuideLandMap[ "colophon"         ] = "colophon";
    m_GuideLandMap[ "copyright-page"   ] = "copyright-page";
    m_GuideLandMap[ "cover"            ] = "cover";
    m_GuideLandMap[ "dedication"       ] = "dedication";
    m_GuideLandMap[ "epigraph"         ] = "epigraph";
    m_GuideLandMap[ "foreword"         ] = "foreword";
    m_GuideLandMap[ "glossary"         ] = "glossary";
    m_GuideLandMap[ "index"            ] = "index";
    m_GuideLandMap[ "loi"              ] = "loi";
    m_GuideLandMap[ "lot"              ] = "lot";
    m_GuideLandMap[ "preface"          ] = "preface";
    m_GuideLandMap[ "title-page"       ] = "titlepage";
    m_GuideLandMap[ "titlepage"        ] = "title-page";
    m_GuideLandMap[ "toc"              ] = "toc";
}
