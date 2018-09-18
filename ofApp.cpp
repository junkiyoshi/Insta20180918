#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(3);
}
//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int length = 30;
	int x_span = 90;
	int y_span = 90;
	for (int x = 0; x < ofGetWidth(); x += x_span) {

		for (int y = 0; y < ofGetHeight(); y += y_span) {

			float x_seed = ofRandom(100);
			float y_seed = ofRandom(100);
			ofPoint point;
			ofPoint prev_point = ofPoint();
			for (int l = 0; l < length; l++) {

				point = ofPoint(ofMap(ofNoise(x_seed, (ofGetFrameNum() + l) * 0.015), 0, 1, x, x + x_span), ofMap(ofNoise(y_seed, (ofGetFrameNum() + l) * 0.015), 0, 1, y, y + y_span));
				if (l != 0) { ofDrawLine(prev_point, point); }
				prev_point = point;
			}

			ofDrawCircle(point, 3);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofGLWindowSettings settings;
	settings.setGLVersion(3, 2);
	settings.setSize(720, 720);
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}